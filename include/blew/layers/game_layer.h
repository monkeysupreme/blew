#pragma once

#include "blew/layer.h"

#include <iostream>

class GameLayer : public blew::Layer
{
public:
    GameLayer() : Layer("GameLayer") {}

    void OnUpdate() override
    {
        std::cout << "GameLayer::OnUpdate()\n";
    }

    void OnRender() override
    {
        std::cout << "GameLayer::OnRender()\n";
    }

    void OnEvent(const SDL_Event& event) override
    {
        if (event.type == SDL_KEYDOWN)
        {
            std::cout << "Key has been pressed!" << std::endl;
        }
    }
};