#include <iostream>
#include "Render.h"
#include "AddNode.h"
#include "InputNode.h"

class VSNode : public VScritImgui::Layer
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
        ImGui::Begin("Empty Node");
        ImGui::Button("Button");
        ImGui::End();

        //ImGui::ShowDemoWindow();
    }
};

class PrintNode : public VScritImgui::Layer
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
        ImGui::Begin("Print Node");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

VScritImgui::Render* VScritImgui::CreateRender(int argc, char** argv)
{
    VScritImgui::Render* render = new VScritImgui::Render();
    render->PushLayer<VSNode>();
    render->PushLayer<PrintNode>();
    render->PushLayer<AddNode>();
    render->PushLayer<InputNode>();

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