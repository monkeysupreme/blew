#pragma once

#include "blew/layer.h"
#include "blew/log.h"

#include <SDL2/SDL.h>

#include <utility>

class InputLayer : public blew::Layer {
public:
    InputLayer(std::shared_ptr<GameLayer> g) : Layer("InputLayer"), m_GameLayer(std::move(g)) {}

    void OnEvent(const SDL_Event& event) override {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_RIGHT) {
                int x = event.button.x;
                int y = event.button.y;

                SDL_Color color = {0, 255, 0};
                std::string name = "Player";

                m_GameLayer->AddEntity(name, x, y, 40, 40, color);
                blew::Logger::Get()->trace("Spawned entity at ({}, {})", x, y);
            }
        }
    }

    void OnUpdate() override {}

private:
    std::shared_ptr<GameLayer> m_GameLayer;

    int m_EntityCounter = 0;
};