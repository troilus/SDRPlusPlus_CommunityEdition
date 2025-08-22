cmake_minimum_required(VERSION 3.13)
project(radio)

file(GLOB_RECURSE SRC "src/*.cpp")

include(${SDRPP_MODULE_CMAKE})

target_include_directories(radio PRIVATE "src/")

# Link FFTW3 for MPX analysis functionality
if (MSVC)
    # On Windows with vcpkg - use the correct target name
    find_package(fftw3 CONFIG REQUIRED)
    target_link_libraries(radio PRIVATE fftw3::fftw3f)
elseif (ANDROID)
    # Android: try to find FFTW3 without pkg-config
    find_library(FFTW3F_LIBRARY fftw3f)
    find_path(FFTW3F_INCLUDE_DIR fftw3.h)
    
    if(FFTW3F_LIBRARY AND FFTW3F_INCLUDE_DIR)
        target_include_directories(radio PRIVATE ${FFTW3F_INCLUDE_DIR})
        target_link_libraries(radio PRIVATE ${FFTW3F_LIBRARY})
    else()
        # If FFTW3 not found, try to link it directly (may be in system libs)
        target_link_libraries(radio PRIVATE fftw3f)
    endif()
else()
    # On Linux/macOS, use pkg-config
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(FFTW3F REQUIRED fftw3f)

    target_include_directories(radio PRIVATE ${FFTW3F_INCLUDE_DIRS})
    target_link_directories(radio PRIVATE ${FFTW3F_LIBRARY_DIRS})
    target_link_libraries(radio PRIVATE ${FFTW3F_LIBRARIES})
endif()