cmake_minimum_required(VERSION 4.1.1)
project(VScrit)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_C_COMPILER "/usr/bin/cc")
set(CMAKE_CXX_COMPILER "/usr/bin/c++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
   message(FATAL_ERROR "In-tree builds are NOT supported.")
endif()

# set_target_properties(
    # VScrit PROPERTIES
    # CXX_STANDARD 17
    # CXX_STANDARD_REQUIRED ON
    # CXX_EXTENSIONS ON
# )

add_compile_definitions(SDL_STATIC)
#set(BUILD_SHARED_LIBS OFF CACHE BOOL "Turn off to disable SDL building shared libs" FORCE)

include(CTest)
enable_testing()

# option(VScrit_VENDORED "Use vendored libraries" OFF)

# if (VScrit_VENDORED)
#     message(STATUS "Using vendored libraries")
add_subdirectory(VScrit/vendor/SDL EXCLUDE_FROM_ALL)
# else()
#     find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3)
#     if(NOT SDL3_FOUND)
#         message(FATAL_ERROR "SDL3 not found!")
#     endif()
# endif()

include(imgui)

# find_package(SDL3 REQUIRED)
# if(NOT SDL3_FOUND)
#     message(FATAL_ERROR "SDL3 not found!")
# endif()
find_package(Vulkan REQUIRED)

add_subdirectory(VScrit/src)
