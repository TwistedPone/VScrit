#include <iostream>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_vulkan.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

static VkInstance g_VulkanInstance = VK_NULL_HANDLE;

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return -1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //ImGui_Impl{platform}_InitForVulkan(window, true);
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;      // Enable Docking

    ImGui::StyleColorsDark();
    ImGui_ImplVulkan_InitInfo init_info = {};
    ImGui_ImplVulkan_Init(&init_info);
    ImGui_ImplVulkan_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some useful text.");
    ImGui::End();
    ImGui::ShowDemoWindow();
    ImGui::Render();
    ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), nullptr);

    // Shutdown ImGui
    ImGui_ImplVulkan_Shutdown();
    ImGui::DestroyContext();

    return 0;
}