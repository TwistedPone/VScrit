#include <iostream>
#include "Render.h"

class ExampleLayer : public VScritImgui::Layer
{
public:
    virtual void OnAttach() override
    {

    }
    
    virtual void OnDetach() override
    {

    }

    virtual void OnUpdate(float ts) override
    {

    }
    
    virtual void OnUIRender() override
    {
        ImGui::Begin("HelloOnuirender");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

VScritImgui::Render* VScritImgui::CreateRender(int argc, char** argv)
{
    VScritImgui::Render* render = new VScritImgui::Render();
    render->PushLayer<ExampleLayer>();
    // render->SetMenuBarCallback([render]() 
    // {
    //     std::cout << "This got called!" << std::endl;
    //     if (ImGui::BeginMenu("File"))
    //     {
    //         if (ImGui::MenuItem("Exit"))
    //             render->Close();
    //         ImGui::EndMenu();
    //     }
        
    // });
    
    return render;
}

int main(int argc, char** argv) {
    static bool started = false;
    if(!started)
    {
        VScritImgui::Render* render = VScritImgui::CreateRender(argc, argv);
        started = true;
        render->Run();
        delete render;
    }
    return 0;
}