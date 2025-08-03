#pragma once

#include "window.h"
#include "input.h"
#include "layer_stack.h"
#include "layers/game_layer.h"
#include "layers/input_layer.h"

#include <string>
#include <iostream>
#include <memory>

namespace blew {

    class Application {
    public:
        Window* WindowPtr{};

        explicit Application(const std::string& name);

        ~Application();

        void Start();

        void PushLayer(const std::shared_ptr<Layer>& layer);

    private:
        std::string m_Name;

        LayerStack m_LayerStack;

    private:
        void InitSDL();

        void InitWindow();
    };

}