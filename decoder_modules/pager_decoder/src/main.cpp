#include <imgui.h>
#include <config.h>
#include <core.h>
#include <gui/style.h>
#include <gui/gui.h>
#include <signal_path/signal_path.h>
#include <module.h>
#include <gui/widgets/folder_select.h>
#include <utils/optionlist.h>
#include "decoder.h"
#include "pocsag/decoder.h"
#include "flex/decoder.h"

#define CONCAT(a, b) ((std::string(a) + b).c_str())

SDRPP_MOD_INFO{
    /* Name:            */ "pager_decoder",
    /* Description:     */ "POCSAG and Flex Pager Decoder"
    /* Author:          */ "Ryzerth",
    /* Version:         */ 0, 1, 0,
    /* Max instances    */ -1
};

ConfigManager config;

enum Protocol {
    PROTOCOL_INVALID = -1,
    PROTOCOL_POCSAG,
    PROTOCOL_FLEX
};

class PagerDecoderModule : public ModuleManager::Instance {
public:
    PagerDecoderModule(std::string name) {
        this->name = name;

        // Define protocols
        protocols.define("POCSAG", PROTOCOL_POCSAG);
        //protocols.define("FLEX", PROTOCOL_FLEX);

        // Initialize VFO with default values
        vfo = sigpath::vfoManager.createVFO(name, ImGui::WaterfallVFO::REF_CENTER, 0, 12500, 24000, 12500, 12500, true);
        vfo->setSnapInterval(1);

        // Select the protocol
        selectProtocol(PROTOCOL_POCSAG);

        gui::menu.registerEntry(name, menuHandler, this, this);
    }

    ~PagerDecoderModule() {
        gui::menu.removeEntry(name);
        // Stop DSP
        if (enabled) {
            decoder->stop();
            decoder.reset();
            sigpath::vfoManager.deleteVFO(vfo);
        }

        sigpath::sinkManager.unregisterStream(name);
    }

    void postInit() {}

    void enable() {
        double bw = gui::waterfall.getBandwidth();
        vfo = sigpath::vfoManager.createVFO(name, ImGui::WaterfallVFO::REF_CENTER, std::clamp<double>(0, -bw / 2.0, bw / 2.0), 12500, 24000, 12500, 12500, true);
        vfo->setSnapInterval(1);

        decoder->setVFO(vfo);
        decoder->start();

        enabled = true;
    }

    void disable() {
        decoder->stop();
        sigpath::vfoManager.deleteVFO(vfo);
        enabled = false;
    }

    bool isEnabled() {
        return enabled;
    }

    void selectProtocol(Protocol newProto) {
        // Cannot change while disabled
        if (!enabled) { return; }

        // If the protocol hasn't changed, no need to do anything
        if (newProto == proto) { return; }

        // Delete current decoder
        decoder.reset();

        // Create a new decoder
        switch (newProto) {
        case PROTOCOL_POCSAG:
            decoder = std::make_unique<POCSAGDecoder>(name, vfo);
             // 订阅消息事件  
            static_cast<POCSAGDecoder*>(decoder.get())->onMessageReceived.bind(&PagerDecoderModule::onMessage, this);  
            break;
        case PROTOCOL_FLEX:
            decoder = std::make_unique<FLEXDecoder>(name, vfo);
            break;
        default:
            flog::error("Tried to select unknown pager protocol");
            return;
        }

        // Start the new decoder
        decoder->start();

        // Save selected protocol
        proto = newProto;
    }
        // 添加消息处理函数  
        void onMessage(pocsag::Address addr, pocsag::MessageType type, const std::string& msg) {  
            std::lock_guard<std::mutex> lck(messagesMtx);  
              
            // 获取当前时间戳  
            auto now = std::chrono::system_clock::now();  
            auto time_t = std::chrono::system_clock::to_time_t(now);  
            char timeStr[64];  
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&time_t));  
              
            // 添加到消息列表  
            messages.push_back({(uint32_t)addr, msg, std::string(timeStr)});  
              
            // 限制消息数量,避免内存无限增长  
            if (messages.size() > 1000) {  
                messages.erase(messages.begin());  
            }  
        }
private:
static void menuHandler(void* ctx) {  
    PagerDecoderModule* _this = (PagerDecoderModule*)ctx;  
    float menuWidth = ImGui::GetContentRegionAvail().x;  
  
    if (!_this->enabled) { style::beginDisabled(); }  
  
    // Protocol selector  
    ImGui::LeftLabel("Protocol");  
    ImGui::FillWidth();  
    if (ImGui::Combo(("##pager_decoder_proto_" + _this->name).c_str(), &_this->protoId, _this->protocols.txt)) {  
        _this->selectProtocol(_this->protocols[_this->protoId]);  
    }  
  
    // Show Messages 按钮  
    if (ImGui::Button(("Show Messages##pager_decoder_messages_" + _this->name).c_str(), ImVec2(menuWidth, 0))) {  
        _this->showMessagesWindow = !_this->showMessagesWindow;  
    }  
  
    // Record 按钮 (保持原样)  
    if (ImGui::Button(("Record##pager_decoder_record_" + _this->name).c_str(), ImVec2(menuWidth, 0))) {  
        // TODO  
    }  
  
    // Decoder specific menu  
    _this->decoder->showMenu();  
  
    if (!_this->enabled) { style::endDisabled(); }  
  
    // 消息显示窗口  
    if (_this->showMessagesWindow) {  
        ImGui::Begin(("POCSAG Messages##" + _this->name).c_str(), &_this->showMessagesWindow, ImGuiWindowFlags_None);  
          
        // 清除按钮  
        if (ImGui::Button("Clear All")) {  
            std::lock_guard<std::mutex> lck(_this->messagesMtx);  
            _this->messages.clear();  
        }  
          
        ImGui::SameLine();  
        ImGui::Text("Total: %d messages", (int)_this->messages.size());  
          
        // 消息表格  
        ImVec2 cellpad = ImGui::GetStyle().CellPadding;  
        if (ImGui::BeginTable("POCSAG Messages Table", 3,   
            ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY | ImGuiTableFlags_Resizable,  
            ImVec2(0, 400.0f * style::uiScale))) {  
              
            ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_WidthFixed, 150.0f * style::uiScale);  
            ImGui::TableSetupColumn("Address", ImGuiTableColumnFlags_WidthFixed, 100.0f * style::uiScale);  
            ImGui::TableSetupColumn("Message");  
            ImGui::TableSetupScrollFreeze(3, 1);  
            ImGui::TableHeadersRow();  
  
            std::lock_guard<std::mutex> lck(_this->messagesMtx);  
            // 倒序显示,最新的在上面  
            for (int i = _this->messages.size() - 1; i >= 0; i--) {  
                auto& msg = _this->messages[i];  
                  
                ImGui::TableNextRow();  
                  
                ImGui::TableSetColumnIndex(0);  
                ImGui::TextUnformatted(msg.timestamp.c_str());  
                  
                ImGui::TableSetColumnIndex(1);  
                ImGui::Text("%u", msg.address);  
                  
                ImGui::TableSetColumnIndex(2);  
                ImGui::TextUnformatted(msg.content.c_str());  
            }  
              
            ImGui::EndTable();  
        }  
          
        ImGui::End();  
    }  
}
    struct DecodedMessage {  
    uint32_t address;  
    std::string content;  
    std::string timestamp;  
    };  
      
    std::vector<DecodedMessage> messages;  
    std::mutex messagesMtx;  
    bool showMessagesWindow = false;

    std::string name;
    bool enabled = true;

    Protocol proto = PROTOCOL_INVALID;
    int protoId = 0;

    OptionList<std::string, Protocol> protocols;

    // DSP Chain
    VFOManager::VFO* vfo;
    std::unique_ptr<Decoder> decoder;

    bool showLines = false;
};

MOD_EXPORT void _INIT_() {
    // Create default recording directory
    json def = json({});
    config.setPath(core::args["root"].s() + "/pager_decoder_config.json");
    config.load(def);
    config.enableAutoSave();
}

MOD_EXPORT ModuleManager::Instance* _CREATE_INSTANCE_(std::string name) {
    return new PagerDecoderModule(name);
}

MOD_EXPORT void _DELETE_INSTANCE_(void* instance) {
    delete (PagerDecoderModule*)instance;
}

MOD_EXPORT void _END_() {
    config.disableAutoSave();
    config.save();
}
