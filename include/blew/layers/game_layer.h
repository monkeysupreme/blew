#pragma once

#include "blew/layer.h"

#include <iostream>

class GameLayer : public blew::Layer
{
public:
    GameLayer() : Layer("GameLayer") {}

    void SetRenderer(SDL_Renderer* renderer)
    {
        m_Renderer = renderer;
    }

    void OnUpdate() override
    {
        std::cout << "GameLayer::OnUpdate()\n";
    }

    void OnRender() override
    {
        if (!m_Renderer) return;

        SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
        SDL_Rect rect = { 100, 100, 200, 150 };
        SDL_RenderFillRect(m_Renderer, &rect);
    }

    void OnEvent(const SDL_Event& event) override
    {
        if (event.type == SDL_KEYDOWN)
        {
            std::cout << "Key has been pressed!" << std::endl;
        }
    }

private:
    SDL_Renderer* m_Renderer = nullptr;
};