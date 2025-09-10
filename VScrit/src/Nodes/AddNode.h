#pragma once

#include "BaseNode.h"
//#include "imgui.h"

class AddNode : public BaseNode
{ public:
    int value = 0;
    virtual const char* GetName() const override { return "Add Node"; }

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
        ImGui::Begin(GetName());
        ImGui::InputInt("Value", &value);

        // Show Connections
        ImGui::Button("Button");
        ImGui::Text("Connected to:");
        for (auto* node : connectedNodes)
        {
            ImGui::BulletText("%s", node->GetName());
        }
        ImGui::End();

        //ImGui::ShowDemoWindow();
    }
};