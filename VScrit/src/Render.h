/*
Borrowed from: TheCherno's ImGui Vulkan Walnut Application.h
Modified by: TwistedPone
Date: September 2025
Purpose: Render class to handle ImGui and Vulkan setup and rendering
*/

#pragma once

#include "Layer.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "imgui.h"
#include "vulkan/vulkan.h"
#include <SDL3/SDL.h>
// #include "imgui_impl_sdl3.h"
// #include "imgui_impl_vulkan.h"

void check_vk_result(VkResult err);

namespace VScritImgui
{
    // Maybe add a Specification struct later
    // struct RenderSpecification {};

    class Render
    {
    public:
        Render();
        ~Render();

        static Render& Get();

        void Run();
        void SetMenuBarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }
        
        template<typename T>
        void PushLayer()
        {
            static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
            m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
        }

        void PushLayer(const std::shared_ptr<Layer>& layer) { m_LayerStack.emplace_back(layer); layer->OnAttach(); }

        void Close();

        float GetTime();
        //SDL_Window* GetWindowHandle() const { return m_WindowHandle; }
        
        static VkInstance GetInstance();
        static VkPhysicalDevice GetPhysicalDevice();
        static VkDevice GetDevice();

        static VkCommandBuffer GetCommandBuffer(bool begin);
        static void FlushCommandBuffer(VkCommandBuffer commandBuffer);

        static void SubmitResourceFree(std::function<void()>&& func);
    private:
        void Init();
        void Shutdown();
    private:
        SDL_Window* m_WindowHandle = nullptr;
        bool m_Running = false;

        float m_TimeStep = 0.0f;
        float m_FrameTime = 0.0f;
        float m_LastFrameTime = 0.0f;

        std::vector<std::shared_ptr<Layer>> m_LayerStack;
        std::function<void()> m_MenubarCallback;
    };

    Render* CreateRender(int argc, char** argv);
} // namespace Render
