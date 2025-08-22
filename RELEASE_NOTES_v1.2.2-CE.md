# SDR++ Community Edition v1.2.2-CE 🌟
## Inaugural Release - The SDR Software That Welcomes Everyone

**Release Date:** August 22, 2025  
**Based on:** SDR++ v1.2.1 
**Repository:** [SDRPlusPlus-CommunityEdition](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition)

---

## 🎯 **What is SDR++ Community Edition?**

SDR++ Community Edition is a **community-driven fork** of SDR++ that addresses the gap in community contributions and feature development. While the original SDR++ project established a solid foundation, many valuable user-requested features remained unaddressed due to restrictive contribution policies.

**Our mission:** Welcome ALL contributors, embrace AI-enhanced development, and rapidly implement features that users actually want.

---

## 🚀 **Major New Features**

### 🎵 **MPX Analysis System for FM Broadcasting** *(Flagship Feature)*
**The most comprehensive FM broadcast analysis tool available in any SDR software**

- **📊 Real-time frequency spectrum analysis** (0-100 kHz)
  - Live FFT visualization of FM multiplex baseband signal
  - Professional frequency band markers with transparent overlays
  - Visual representation of MONO (0-15kHz), PILOT (19kHz), STEREO (23-53kHz), RDS (55-59kHz), SCA (65-94kHz)

- **📈 Time-domain channel analysis**
  - L+R (mono sum) channel visualization
  - L-R (stereo difference) channel analysis  
  - Individual Left and Right channel displays
  - Synchronized with spectrum analysis

- **⚙️ Fully configurable settings**
  - MPX refresh rate (1-60 Hz) for performance optimization
  - Line width control (0.5-5.0px) for spectrum display clarity
  - Smoothing factor (1-10) for noise reduction vs responsiveness
  - All settings persist between sessions

- **🔧 Technical excellence**
  - FFTW3-powered efficient real-time processing
  - Thread-safe implementation with mutex protection
  - Non-blocking design preserves main audio path performance
  - Dynamic sample rate detection
  - Exponential moving average smoothing

### 📡 **Enhanced Scanner Module**
**Improved frequency scanning with blacklisting and persistence**

- **🚫 Frequency blacklisting** 
  - Exclude specific frequencies from scanning
  - Persistent blacklist that survives app restarts
  - Easy management of unwanted frequencies

- **💾 Configuration persistence**
  - Scanner settings now persist between sessions
  - Scan ranges, step sizes, and preferences saved automatically
  - No more losing your scanning configuration on restart

- **🔧 Improved usability**
  - Better workflow for managing scan lists
  - Enhanced user interface for blacklist management
  - More reliable scanning behavior

### 📊 **FFT Zoom Persistence**
**Finally! FFT zoom settings that remember where you left them**

- **🎯 Complete zoom persistence**
  - FFT zoom level automatically saved when changed
  - Zoom setting restored exactly on app restart
  - No more losing your preferred FFT view

- **🎪 Perfect centering**
  - FFT view properly centered on tuned frequency
  - VFO offset correctly applied during initialization
  - Eliminates the frustrating frequency drift issue

- **⚡ Immediate application**
  - Zoom and centering applied instantly on startup
  - No need to touch the slider to activate saved settings
  - Seamless user experience across sessions

### 🛠️ **Enhanced Configuration Management**
**Robust, schema-first configuration architecture**

- **Schema-first design** prevents "unused key" deletion issues
- **Platform-aware config paths** for proper macOS app bundle support
- **Unified default constants** for maintainable code
- **Comprehensive debugging methodology** documented in cursor rules
- **Persistent settings** that actually persist (fixed major config bugs)

### 🍎 **Improved macOS Support**
**Better compatibility and ARM processor support**

- **Fixed app bundle creation** with correct module alignment
- **M17 decoder ARM compatibility** for Apple Silicon Macs
- **Corrected library dependency paths** in app bundles
- **Enhanced build system** with proper CMake configuration

---

## 📚 **Documentation Transformation**

### 🤝 **Community-First Documentation**
**From restrictive to enthusiastically welcoming**

**Before:**
- ❌ "Code pull requests are **NOT welcome**"
- Discouraging contribution barriers
- Limited guidance for new contributors

**After:**
- ✅ "Code contributions ARE ENTHUSIASTICALLY WELCOME!" 🎉
- Step-by-step contribution process
- Guidance for beginners AND experts
- Transparent, fair review process
- AI-enhanced development friendly

### 📖 **Comprehensive README Overhaul**
- Clear Community Edition mission statement
- Professional installation instructions
- Feature showcase with screenshots
- Community contribution guidelines
- Links to Community Edition resources

---

## 🔧 **Technical Improvements**

### **Core Architecture Enhancements**
- **9 files modified** for MPX analysis integration
- **Enhanced DSP chain** with optional MPX output streams
- **ImGui custom rendering** for professional spectrum visualization
- **Thread-safe data handling** throughout the application

### **Build System Fixes**
- Corrected `make_macos_bundle.sh` script alignment with actual build targets
- Fixed module references and dependency paths
- Enhanced CMake configuration for bundle defaults
- Proper app signing and library linking

### **Code Quality**
- **1,714 net lines added** of well-documented, professional code
- Comprehensive error handling and edge case management
- Consistent coding standards throughout
- Extensive inline documentation

---

## 📊 **Release Statistics**

- **🏗️ Development effort:** 4 major commits, 23 files changed
- **📝 Code changes:** 2,257 lines added, 543 lines removed (net +1,714)
- **🎯 New features:** 1 major (MPX analysis) + multiple enhancements
- **🔧 Bug fixes:** Configuration persistence, build system, macOS compatibility
- **📚 Documentation:** Complete README and contributing.md transformation
- **🧪 Compatibility:** 100% backward compatible with original SDR++

---

## 🎨 **User Experience Improvements**

### **Enhanced Display Menu**
- Collapsible "MPX Analysis Settings" section
- Intuitive controls for all MPX parameters
- Real-time settings updates with immediate visual feedback
- Organized layout for better usability

### **Professional Visualization**
- Color-coded frequency bands with transparency
- Bright spectrum lines with glow effects for visibility
- Smart label positioning to prevent overlaps
- Consistent graph sizing across all analysis views

### **Performance Optimization**
- Configurable refresh rates to balance quality vs CPU usage
- Non-blocking processing preserves main signal path
- Efficient memory management for real-time operation
- Smart smoothing algorithms for clean displays

---

## 🚀 **Installation & Compatibility**

### **Download Options**
- **Community Edition releases:** Latest features and community improvements
- **Original compatibility:** 100% compatible with existing SDR++ configurations
- **Cross-platform:** Windows, Linux, macOS (including Apple Silicon)

### **System Requirements**
- Same as original SDR++ (no additional dependencies for basic functionality)
- FFTW3 library for MPX analysis (typically pre-installed)
- Compatible with all existing SDR hardware and plugins

---

## 🌟 **Looking Forward**

### **Community Roadmap**
This inaugural release establishes SDR++ Community Edition as the platform for:

- **Rapid feature development** addressing real user needs
- **AI-enhanced development** welcome and encouraged
- **Open collaboration** from beginners to experts
- **Transparent development** with fair review processes
- **User-driven priorities** rather than top-down decisions

### **Planned Enhancements**
- Additional protocol decoders requested by the community
- Enhanced visualization tools for signal analysis
- Mobile/tablet UI optimizations
- Performance improvements for resource-constrained systems
- Expanded hardware support through community contributions

---

## 🙏 **Acknowledgments**

**Original SDR++ Team:** For creating the excellent foundation that made this possible.

**Community Contributors:** Every suggestion, bug report, and feature request helps shape this Community Edition.

**AI-Enhanced Development:** This release proudly embraces modern development tools and methodologies.

---

## 📞 **Community & Support**

- **🏠 Homepage:** [SDRPlusPlus-CommunityEdition](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition)
- **🐛 Issues & Bug Reports:** [GitHub Issues](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/issues)
- **💬 Discussions:** [GitHub Discussions](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/discussions)
- **🤝 Contributing:** See our welcoming [Contributing Guidelines](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/blob/master/contributing.md)

---

## 🎉 **Join the Community Edition Movement**

SDR++ Community Edition represents a **new paradigm** in open source SDR software development:

- **Your contributions matter** - from typo fixes to major features
- **Your voice is heard** - user requests drive development priorities  
- **Your expertise is valued** - whether you're a beginner or expert
- **Your tools are welcome** - AI-enhanced development embraced

**Download today and experience the difference when a project truly welcomes its community!**

---

**🌟 Welcome to SDR++ Community Edition - where every contribution matters! 🌟**
