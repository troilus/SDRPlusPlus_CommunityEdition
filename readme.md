# SDR++ Community Edition 🌟
## The bloat-free SDR software that welcomes everyone

![Screenshot](wiki/mpx_analysis.png)

**SDR++ Community Edition** is a community-driven fork of the original SDR++ - a cross-platform and open source SDR software with the aim of being bloat free and simple to use.

### 🎯 **Mission: Community-First Development**

This Community Edition exists to address the gap in community contributions and feature development. While the original SDR++ project has established a solid foundation, many valuable user-requested features and improvements have remained unaddressed due to restrictive contribution policies.

**Our commitment:**
- ✅ **Welcome ALL contributors** - from beginners to experts
- ✅ **AI-enhanced development friendly** - we embrace modern development tools
- ✅ **Rapid feature development** - addressing user requests that matter
- ✅ **Transparent review process** - all contributions are reviewed fairly
- ✅ **Community-driven priorities** - features requested by users, built by the community

### 🚀 **New in Community Edition**
- **MPX Analysis for FM Broadcasting** - Real-time multiplex signal analysis with frequency spectrum visualization
- **Enhanced Scanner Module** - Frequency blacklisting and persistent configuration settings
- **FFT Zoom Persistence** - FFT zoom level and centering now persist between app restarts
- **Enhanced Configuration Management** - Improved settings persistence and architecture
- **Build System Improvements** - Better macOS support and ARM compatibility
- **Comprehensive Documentation** - Architecture guidelines for contributors

### 🤝 **Contributing**
We actively encourage contributions! Whether you're fixing bugs, adding features, improving documentation, or enhancing the user experience - **your contribution is welcome**.

**How to contribute:**
1. Fork this repository
2. Create a feature branch
3. Make your improvements
4. Submit a pull request
5. Engage in the review process

**No contribution is too small** - from typo fixes to major features, we value all community input.

---

### 📊 **Repository Links**
- 🏠 **Community Edition**: [SDRPlusPlus-CommunityEdition](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition)
- 📞 **Community Support**: [Issues & Discussions](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/issues)
- 🔗 **Original Project**: [AlexandreRouma/SDRPlusPlus](https://github.com/AlexandreRouma/SDRPlusPlus)

## Features

* Multi VFO
* Wide hardware support (both through SoapySDR and dedicated modules)
* SIMD accelerated DSP
* Cross-platform (Windows, Linux, MacOS and BSD)
* Full waterfall update when possible. Makes browsing signals easier and more pleasant
* Modular design (easily write your own plugins)
* **NEW: MPX Analysis** - Real-time FM broadcast multiplex signal analysis with frequency spectrum visualization
* **NEW: Enhanced Scanner** - Frequency blacklisting and persistent configuration settings
* **NEW: FFT Zoom Persistence** - FFT zoom level and centering settings persist between restarts

# Installing

## Community Edition Releases

**SDR++ Community Edition** releases include the latest community-contributed features and improvements. Download the latest release from the [Community Edition Releases page](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/releases).

### Original SDR++ Compatibility
This Community Edition maintains full compatibility with original SDR++ configurations and plugins. You can also download original SDR++ builds from the [original project's releases](https://github.com/AlexandreRouma/SDRPlusPlus/releases) if preferred.

## Windows

Download the latest release from [the Community Edition Releases page](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/releases) and extract to the directory of your choice.

To create a desktop shortcut, rightclick the exe and select `Send to -> Desktop (create shortcut)`, then, rename the shortcut on the desktop to whatever you want.

## Linux

### Debian-based (Ubuntu, Mint, etc)

Download the latest release from [the Community Edition Releases page](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/releases) and extract to the directory of your choice.

Then, use apt to install it:

```sh
sudo apt install path/to/the/sdrpp_debian_amd64.deb
```

**IMPORTANT: You must install the drivers for your SDR. Follow instructions from your manufacturer as to how to do this on your particular distro.**

### Arch Linux (AUR)
```sh
yay -S sdrpp-git
```

**WARNING: The sdrpp-git AUR package is no longer official, it is not recommended to use it.**

### Other

There are currently no existing packages for other distributions, for these systems you'll have to [build from source](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition#building-on-linux--bsd).

## MacOS

**Community Edition**: Download the latest macOS app bundle from [Community Edition Releases](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition/releases).

**Original SDR++**: Alternatively, download from the original [nightly build](https://www.sdrpp.org/nightly)

## BSD

There are currently no BSD packages, refer to [Building on Linux / BSD](https://github.com/miguel-vidal-gomes/SDRPlusPlus-CommunityEdition#building-on-linux--bsd) for instructions on building from source.

# Building on Windows

The preferred IDE is [VS Code](https://code.visualstudio.com/) in order to have similar development experience across platforms and to build with CMake using the command line.

## Installing dependencies

* Install [cmake](https://cmake.org)
* Install [vcpkg](https://github.com/Microsoft/vcpkg)
* Run `vcpkg/vcpkg install fftw3:x64-windows glfw3:x64-windows portaudio:x64-windows zstd:x64-windows libusb:x64-windows`
* Install [OpenGL](https://www.microsoft.com/en-us/download/details.aspx?id=55839)

## Building

```
mkdir build
cd build
cmake .. "-DCMAKE_TOOLCHAIN_FILE=C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake" -DMSVC_RUNTIME=dynamic
cmake --build . --config Release
```

## Running for development

If you wish to install SDR++ Community Edition, skip to the next step

You will first need to edit the `Root Directory` field in the config menu to point to the `root_dev` folder.

You will also need to copy the following modules that don't build as plugins to the `root_dev/modules` folder:
* `audio_sink`

## Installing SDR++ Community Edition

If you chose to run SDR++ Community Edition for development, DO NOT perform this step.

In the build directory, run:
```
cmake --install . --config Release
```

# Building on Linux / BSD

## Select which modules you wish to build

Duplicate the `build_options.txt` file into a new file called `build_options.local.txt` and edit to your needs.
Here are additional modules that you can enable in your `build_options.local.txt`:

* `OPT_BUILD_AIRSPY_SOURCE` - For Airspy devices
* `OPT_BUILD_AIRSPYHF_SOURCE` - For Airspy HF+ devices
* `OPT_BUILD_BLADERF_SOURCE` - For BladeRF devices
* `OPT_BUILD_LIMESDR_SOURCE` - For LimeSDR devices
* `OPT_BUILD_PERSEUS_SOURCE` - For Perseus devices
* `OPT_BUILD_PLUTOSDR_SOURCE` - For PlutoSDR devices
* `OPT_BUILD_HACKRF_SOURCE` - For HackRF devices
* `OPT_BUILD_RTL_TCP_SOURCE` - For connecting to rtl_tcp instances
* `OPT_BUILD_SDRPP_SERVER_SOURCE` - For connecting to other SDR++ instances remotely
* `OPT_BUILD_SPYSERVER_SOURCE` - For connecting to SpyServer instances
* `OPT_BUILD_SOAPY_SOURCE` - For SoapySDR devices (WARNING: Produces very messy code as of right now)

## Installing dependencies

Note: This guide was written for Ubuntu 22. Some distributions may have older versions of packages that will not work. If so, compile from source and install newer versions.

### Core dependencies

* `build-essential`
* `cmake`
* `pkg-config`
* `libfftw3-dev`
* `libglfw3-dev`
* `libvolk2-dev` (Ubuntu 22+) or `libvolk1-dev` (Ubuntu 20)
* `libzstd-dev`

### Additional dependencies depending on modules used

* `libairspy-dev` - For Airspy devices
* `libairspyhf-dev` - For Airspy HF+ devices
* `libbladerf-dev` - For BladeRF devices
* `libiio-dev libad9361-dev` - For PlutoSDR devices
* `libhackrf-dev` - For HackRF devices
* `librtaudio-dev` - For audio sink
* `libusb-1.0-0-dev` - For Perseus, BladeRF
* `libjsoncpp-dev` - For some digital decoders
* `libcodec2-dev` - For M17 digital decoder

Note: make sure you're using `libvolk2-dev`, NOT `libvolk1-dev` as the latter will cause a crash

## Building

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j2
```

### Building with more options

You can specify more build options by adding the options listed in `build_options.txt` to the cmake command as such:
```
cmake .. -DCMAKE_BUILD_TYPE=Release -DOPT_BUILD_BLADERF_SOURCE=ON -DOPT_BUILD_LIMESDR_SOURCE=ON -DOPT_BUILD_SDRPP_SERVER_SOURCE=ON
```

Alternatively, to enable all available modules for your distribution:
```
cmake .. -DCMAKE_BUILD_TYPE=Release -DOPT_OVERRIDE_BUILD_OPTIONS=ON
```

For macOS with ARM CPUs, add:
```
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DUSE_BUNDLE_DEFAULTS=ON
```

## Installing SDR++ Community Edition

To install SDR++ Community Edition run the following command in your `build` folder:
```
sudo make install
```

The installation will by default be `/usr` for packaging purpses, you can specify a custom directory with:
```
sudo make install DESTDIR=/usr/local
```

## Building a .deb package

To build a .deb package, run:
```
make package
```

## Building on OSX

### Installing dependencies

```
brew tap pothosware/homebrew-pothos
brew install portaudio fftw glfw airspy airspyhf hackrf rtl-sdr libbladerf codec2 zstd autoconf automake libtool && brew install --HEAD volk
```

You may also want to install the `limesuite` package from pothos for LimeSDR support.

### Building

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DUSE_BUNDLE_DEFAULTS=ON
make -j4
```

Or, if you want to use MacPorts to install dependencies:

```
sudo port install fftw-3 +universal glfw +universal volk +universal zstd +universal autoconf automake libtool
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DUSE_BUNDLE_DEFAULTS=ON -DCMAKE_PREFIX_PATH=/opt/local
make
```

Using homebrew dependencies seems to work fine for most modules, but on Macs with Apple Silicon SoapySDR crashes SDR++ pretty hard...

### Create a .app bundle

**Note: This process is only available on macOS**

First, build the project:
```bash
make -j8
```

Then, from the project root directory (not build directory), create the app bundle:
```bash
cd ..
./make_macos_bundle.sh build ./SDR++CE.app
```

This will create a `SDR++CE.app` bundle in your project root directory that you can launch with:
```bash
open SDR++CE.app
```

For detailed instructions, see `MACOS_BUILD_INSTRUCTIONS.md`.

# Module List

Not all modules are built by default. I decided to disable the build of those with large dependencies or that are still in beta.
Modules in beta are still included in releases for the most part but not enabled in the cmake file.

The signal_path module is not optional and always included.

## Sources

| Name                     | Stage       | Dependencies         | Option                        | Built by default |
|--------------------------|-------------|----------------------|-------------------------------|:----------------:|
| airspy_source            | Working     | libairspy            | OPT_BUILD_AIRSPY_SOURCE       |     false        |
| airspyhf_source          | Working     | libairspyhf          | OPT_BUILD_AIRSPYHF_SOURCE     |     false        |
| audio_source             | Working     | portaudio            | OPT_BUILD_AUDIO_SOURCE        |     true         |
| bladerf_source           | Working     | libbladeRF           | OPT_BUILD_BLADERF_SOURCE      |     false        |
| file_source              | Working     | -                    | OPT_BUILD_FILE_SOURCE         |     true         |
| hackrf_source            | Working     | libhackrf            | OPT_BUILD_HACKRF_SOURCE       |     false        |
| hermes_source            | Working     | -                    | OPT_BUILD_HERMES_SOURCE       |     false        |
| limesdr_source           | Working     | libLimeSuite         | OPT_BUILD_LIMESDR_SOURCE      |     false        |
| network_source           | Working     | -                    | OPT_BUILD_NETWORK_SOURCE      |     true         |
| perseus_source           | Working     | libperseus-sdr       | OPT_BUILD_PERSEUS_SOURCE      |     false        |
| plutosdr_source          | Working     | libiio, libad9361    | OPT_BUILD_PLUTOSDR_SOURCE     |     false        |
| rfspace_source           | Working     | -                    | OPT_BUILD_RFSPACE_SOURCE      |     false        |
| rtl_sdr_source           | Working     | librtlsdr            | OPT_BUILD_RTL_SDR_SOURCE      |     true         |
| rtl_tcp_source           | Working     | -                    | OPT_BUILD_RTL_TCP_SOURCE      |     true         |
| sdrplay_source           | Unfinished  | SDRplay API          | OPT_BUILD_SDRPLAY_SOURCE      |     false        |
| sdrpp_server_source      | Working     | -                    | OPT_BUILD_SDRPP_SERVER_SOURCE |     true         |
| soapy_source             | Working     | soapysdr             | OPT_BUILD_SOAPY_SOURCE        |     false        |
| spyserver_source         | Working     | -                    | OPT_BUILD_SPYSERVER_SOURCE    |     true         |
| spectran_http_source     | Working     | -                    | OPT_BUILD_SPECTRAN_HTTP_SOURCE|     false        |

## Sinks

| Name                 | Stage       | Dependencies | Option                    | Built by default |
|----------------------|-------------|--------------|---------------------------|:----------------:|
| audio_sink           | Working     | portaudio    | OPT_BUILD_AUDIO_SINK      |     true         |
| network_sink         | Working     | -            | OPT_BUILD_NETWORK_SINK    |     true         |
| new_portaudio_sink   | Beta        | portaudio    | OPT_BUILD_NEW_PORTAUDIO_SINK |  false       |

## Decoders

| Name                 | Stage       | Dependencies | Option                    | Built by default |
|----------------------|-------------|--------------|---------------------------|:----------------:|
| atv_decoder          | Unfinished  | -            | OPT_BUILD_ATV_DECODER     |     false        |
| falcon9_decoder      | Working     | ffplay       | OPT_BUILD_FALCON9_DECODER |     false        |
| kg_sstv_decoder      | Working     | -            | OPT_BUILD_KG_SSTV_DECODER |     false        |
| m17_decoder          | Working     | codec2       | OPT_BUILD_M17_DECODER     |     false        |
| meteor_demodulator   | Working     | -            | OPT_BUILD_METEOR_DEMODULATOR |   true        |
| pager_decoder        | Working     | -            | OPT_BUILD_PAGER_DECODER   |     false        |
| radio                | Working     | -            | OPT_BUILD_RADIO           |     true         |
| vor_receiver         | Beta        | -            | OPT_BUILD_VOR_RECEIVER    |     false        |
| weather_sat_decoder  | Working     | -            | OPT_BUILD_WEATHER_SAT_DECODER |  false       |

## Misc

| Name                 | Stage       | Dependencies | Option                        | Built by default |
|----------------------|-------------|--------------|-------------------------------|:----------------:|
| discord_integration  | Working     | -            | OPT_BUILD_DISCORD_INTEGRATION |     false        |
| frequency_manager    | Working     | -            | OPT_BUILD_FREQUENCY_MANAGER   |     true         |
| iq_exporter          | Working     | -            | OPT_BUILD_IQ_EXPORTER         |     false        |
| recorder             | Working     | -            | OPT_BUILD_RECORDER            |     true         |
| rigctl_client        | Working     | -            | OPT_BUILD_RIGCTL_CLIENT       |     false        |
| rigctl_server        | Working     | -            | OPT_BUILD_RIGCTL_SERVER       |     false        |
| scanner              | Working     | -            | OPT_BUILD_SCANNER             |     true         |

# Troubleshooting

First, please make sure you're running the latest automated build. If your issue is linked to a bug it is likely that is has already been fixed in later releases

## "hash collision" error on Windows

You might see this error if you're using a 64 bit machine but didn't install the visual C++ redistributable x64 version.

## "Illegal instruction" crash on startup

If SDR++ Community Edition crashes with an "Illegal instruction" error, this is due to your CPU being too old to support SIMD instructions that speed up SDR++.
You can get around this by editing `config.json` (`~/.config/sdrpp/config.json` on Linux) and changing `fastFFT` to false and `bufferSize` to 262144.

This isn't great however as it will slow down SDR++ Community Edition quite significantly.

## GUI stuck in "Initializing" state

This is usually caused by the graphics drivers not being properly installed. This can happen when using a headless/server version of Linux distributions. Install graphics drivers or enable headless mode by adding `-s` to the command line arguments.

## "[$mod_name] Unknown command"

If you see this error, you're trying to use a feature that hasn't been implemented for the particular SDR you're using. Check the modules list above to see which modules support the feature you're trying to use.

You can switch to a different source using the dropdown menu in the source selection widget.

## Audio crackling on Raspberry Pi

This is a CPU usage issue. The default buffer size is too small for the Pi's limited processing power.
Edit `config.json` and change the `bufferSize` value to `4096000`.

## Noise when zooming in HackRF

The HackRF has the annoying tendency to have a DC offset spike. You can avoid this by activating the "Offset Tuning" option in the source settings.

## Setting up the development environment

SDR++ Community Edition uses CMake for compilation and [vcpkg](https://github.com/microsoft/vcpkg) for dependency management on Windows.

### On Windows

Install dependencies:
```
vcpkg/vcpkg install fftw3:x64-windows glfw3:x64-windows portaudio:x64-windows zstd:x64-windows libusb:x64-windows
```

### On Linux

Install dependencies:
```
sudo apt install build-essential cmake git pkg-config libfftw3-dev libglfw3-dev libvolk2-dev libzstd-dev librtaudio-dev libusb-1.0-0-dev libjsoncpp-dev libcodec2-dev
```

Note: Some older distributions don't have `libvolk2-dev`. Use `libvolk1-dev` instead.

### Cross platform building

SDR++ Community Edition uses CMake, which allows for easy cross-platform compilation.
Some modules that are included will not work on all platforms. For example the "audio_sink" module uses the portaudio library, which may not always be available.

Please make sure to disabling the modules you don't need with the module build options.

### How to create modules

To create a new module, start by copying the "demo_module" folder and rename it to whatever you like.
You will need to edit the `CMakeLists.txt` to change the module name. The module name should be the name of the folder.

You will of course also need to edit the `.cpp` file to implement your module. 
The demo module is there to show how to use the API. If you are familiar with the concepts behind GNU Radio, the `process` function should be familiar to you.

To enable the module you created, add a line to the root CMakeLists.txt file with your module name `option(OPT_BUILD_NEW_MODULE "Build my new module" ON)`.

For guidance, check the existing modules.
If you are creating a source, look at the existing source modules.
If you are creating a sink, look at the "network_sink" module.
If you are creating a decoder, look at the "radio" module.

Remember that headers for the core need to be included as `#include <utils/flog.h>` for every module.

Of course, don't forget to add the option to build it to the config.
In addition, use `OPT_BUILD_MYMODULE` to disable the module in module_list.hpp if it should not be built.

## Contributing to core

When contributing to the core, please try to maintain the current "programming style".
While there isn't a style guide, the formatting is done using clang-format.

The best way to familiarize yourself with the core is to look at the source files and see how SDR++ Community Edition is structured.

This project was mainly written by one person, so it might not be the best software architecture. I am open to critiques of the code and how to improve it.

## Other contributions

While software contributions are preferred, SDR++ Community Edition always welcomes other types of contributions.
If you would like to contribute in other ways or have questions not related to software, please see:

### Donations

If you want to support the continued development of **SDR++CE Community Edition**, you can do so via [Patreon](https://www.patreon.com/c/miguel_vidal_gomes). 

Or, if you are a company and want to integrate SDR++ into your workflow or add functionality specific to your hardware, you can reach out for custom SDR++CE features or professional support.

---

**Welcome to SDR++ Community Edition - where every contribution matters! 🚀**