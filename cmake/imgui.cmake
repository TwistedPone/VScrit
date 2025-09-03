# ImGui CMake configuration file from rahituber
# https://github.com/ThomasR95/rahituber/blob/main/cmake/imgui.cmake
add_library(imgui STATIC
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/backends/imgui_impl_sdl3.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/backends/imgui_impl_sdl3.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/backends/imgui_impl_vulkan.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/backends/imgui_impl_vulkan.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imconfig.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui_demo.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui_internal.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imstb_rectpack.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imstb_textedit.h
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/imstb_truetype.h
)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui/backends
)

target_link_libraries(imgui PUBLIC SDL3::SDL3 Vulkan::Vulkan)