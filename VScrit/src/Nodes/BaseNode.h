#pragma once
#include "Render.h"

class BaseNode : public VScritImgui::Layer
{ public:
    struct Pin {
        enum class Type { Input, Output } type;
        int id;
    };
    std::vector<BaseNode*> inputs;
    std::vector<BaseNode*> outputs;
    std::vector<BaseNode*> connectedNodes;

    virtual const char* GetName() const = 0;

    void ConnectTo(BaseNode* other)
    {
        connectedNodes.push_back(other);
    }

    // Optionally, add methods to disconnect, get connections, etc.
};