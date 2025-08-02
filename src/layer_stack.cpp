//
// Created by caleb on 8/2/25.
//

#include <algorithm>
#include "blew/layer_stack.h"

namespace blew {

    void LayerStack::PushLayer(std::shared_ptr<Layer> layer) {
        layer->OnAttach();
        m_Layers.emplace_back(layer);
    }

    void LayerStack::PopLayer(const std::string &name) {
        auto it = std::remove_if(m_Layers.begin(), m_Layers.end(),
             [&name](const std::shared_ptr<Layer>& layer) {
            return layer->GetName() == name;
        });
        if (it != m_Layers.end())
        {
            (*it)->OnDetach();
            m_Layers.erase(it, m_Layers.end());
        }
    }

}