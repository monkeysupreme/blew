#pragma once

#include "layer.h"

#include <memory>
#include <vector>

namespace blew {

    class LayerStack
    {
    public:
        void PushLayer(std::shared_ptr<Layer> layer);
        void PopLayer(const std::string& name);

        std::vector<std::shared_ptr<Layer>>& GetLayers() { return m_Layers; }

    private:
        std::vector<std::shared_ptr<Layer>> m_Layers;
    };

}