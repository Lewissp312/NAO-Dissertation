cmake_minimum_required(VERSION 3.10)

project(NAO-Dissertation)

# ===== main =====

# Create the executable
add_executable(main
    src/main.cpp
    src/NaoConnection.cpp
)
set_target_properties(main PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

# Platform-specific settings
if(WIN32)
    set(NAOQI_SDK_PATH "${CMAKE_SOURCE_DIR}/external/naoqi-sdk-2.8.5.10-win64")
    target_compile_options(main PRIVATE /EHsc)
    target_compile_definitions(main PRIVATE _GLIBCXX_USE_CXX11_ABI=0)
elseif(APPLE)
    set(NAOQI_SDK_PATH "${CMAKE_SOURCE_DIR}/external/naoqi-sdk-2.8.5.10-mac64")
    target_compile_options(main PRIVATE -std=gnu++11)
elseif(UNIX AND NOT APPLE)
    set(NAOQI_SDK_PATH "${CMAKE_SOURCE_DIR}/external/naoqi-sdk-2.8.5.10-linux64")
    target_compile_options(main PRIVATE -std=gnu++11)
    target_compile_definitions(main PRIVATE _GLIBCXX_USE_CXX11_ABI=0)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Include & link NAOQI dependencies
target_include_directories(main PRIVATE ${NAOQI_SDK_PATH}/include)
target_link_directories(main PRIVATE ${NAOQI_SDK_PATH}/lib)

# Platform specific libraries
if (WIN32)
    target_link_libraries(main
        qi
        alcommon
        alerror
        alproxies
        alvalue
        boost_system-vc141-mt-1_69
        boost_thread-vc141-mt-1_69
        opencv_core310
        opencv_highgui310
        opencv_imgcodecs310
        opencv_imgproc310
    )
    
    # Windows DLL handling - copy DLLs to output directory
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${NAOQI_SDK_PATH}/bin" $<TARGET_FILE_DIR:main>
    )
elseif(UNIX OR APPLE)
    target_link_libraries(main
        qi
        alcommon
        alerror
        alproxies
        alvalue
        boost_system
        boost_thread
        opencv_core
        opencv_highgui
        opencv_imgcodecs
        opencv_imgproc
    )

    # rpath to help locate .so or .dylib files at runtime
    set_target_properties(main PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH_USE_LINK_PATH TRUE
        BUILD_RPATH "${NAOQI_SDK_PATH}/lib"
        INSTALL_RPATH "${NAOQI_SDK_PATH}/lib"
    )
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# ===== Executable 2: Image Tool =====

add_executable(
    imaging src/PictureEnhancement.cpp
)

# Optional: Use a different C++ version for this target
set_target_properties(imaging PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if(WIN32)
    set(LIBTORCH_PATH "${CMAKE_SOURCE_DIR}/external/libtorch-win64")
    target_compile_options(imaging PRIVATE /EHsc)
    target_compile_definitions(imaging PRIVATE _GLIBCXX_USE_CXX17_ABI=0)
elseif(APPLE)
    set(LIBTORCH_PATH "${CMAKE_SOURCE_DIR}/external/libtorch-mac64")
    target_compile_options(imaging PRIVATE -std=gnu++17)
elseif(UNIX AND NOT APPLE)
    set(LIBTORCH_PATH "${CMAKE_SOURCE_DIR}/external/libtorch-linux64")
    target_compile_options(imaging PRIVATE -std=gnu++17)
    target_compile_definitions(imaging PRIVATE _GLIBCXX_USE_CXX17_ABI=0)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

target_include_directories(imaging PRIVATE 
	${LIBTORCH_PATH}/include
	${LIBTORCH_PATH}/include/torch/csrc/api/include
	${NAOQI_SDK_PATH}/include
)
target_link_directories(imaging PRIVATE 
	${LIBTORCH_PATH}/lib
	${NAOQI_SDK_PATH}/lib
)

if (WIN32)
    target_link_libraries(imaging
	torch
	c10	
	torch_cpu
        opencv_core310
        opencv_highgui310
        opencv_imgcodecs310
        opencv_imgproc310
    )
    
    # Windows DLL handling - copy DLLs to output directory
    add_custom_command(TARGET imaging POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${LIBTORCH_PATH}/bin" $<TARGET_FILE_DIR:imaging>
    )
elseif(UNIX OR APPLE)
    target_link_libraries(imaging
	torch
	c10	
	torch_cpu
        opencv_core
        opencv_highgui
        opencv_imgcodecs
        opencv_imgproc
    )

    # rpath to help locate .so or .dylib files at runtime
    set_target_properties(imaging PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH_USE_LINK_PATH TRUE
        BUILD_RPATH "${LIBTORCH_PATH}/lib;${NAOQI_SDK_PATH}/lib"
        INSTALL_RPATH "${LIBTORCH_PATH}/lib;${NAOQI_SDK_PATH}/lib"
    )
else()
    message(FATAL_ERROR "Unsupported platform")
endif()
