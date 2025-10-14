#pragma once
#include <signal_path/vfo_manager.h>
#include <ctime>  
#include <mutex>  
#include <vector>

class Decoder {
public:
    virtual ~Decoder() {}
    virtual void showMenu() {};
    virtual void setVFO(VFOManager::VFO* vfo) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};
