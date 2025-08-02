#pragma once

#include "window.h"
#include "layers/game_layer.h"

#include <string>
#include <iostream>
#include <memory>

namespace blew {

    class Application
    {
    public:
        Window* WindowPtr{};

        explicit Application(const std::string& name);
        ~Application();

        void Start();

    private:
        std::string m_Name;

        std::shared_ptr<GameLayer> m_GameLayer;

    private:
        void InitSDL();
        void InitWindow();
    };

}