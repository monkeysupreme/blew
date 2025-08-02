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

        std::vector<std::shared_ptr<Layer>>::iterator begin() { return m_Layers.begin(); }
        std::vector<std::shared_ptr<Layer>>::iterator end() { return m_Layers.end(); }
        std::vector<std::shared_ptr<Layer>>::const_iterator begin() const { return m_Layers.begin(); }
        std::vector<std::shared_ptr<Layer>>::const_iterator end() const { return m_Layers.end(); }

    private:
        std::vector<std::shared_ptr<Layer>> m_Layers;
    };

}