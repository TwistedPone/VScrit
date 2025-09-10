#pragma once

#include "BaseNode.h"

class InputNode : public BaseNode {
public:
    int value = 0;
    virtual const char* GetName() const override { return "Input Node"; }

    virtual void OnUIRender() override {
        ImGui::Begin(GetName());
        ImGui::InputInt("Value", &value);

        // Show connections
        ImGui::Text("Connected to:");
        for (auto* node : connectedNodes) {
            ImGui::BulletText("%s", node->GetName());
        }

        ImGui::End();
    }
};