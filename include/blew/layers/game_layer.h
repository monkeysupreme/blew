#pragma once

#include "blew/layer.h"
#include "blew/entity.h"

#include <iostream>

class GameLayer : public blew::Layer {
public:
    GameLayer() : Layer("GameLayer"), m_Camera(0, 0, 500, 500) {
        AddEntity("Player", 100, 100, 50, 50, SDL_Color{0, 0, 255});
        AddEntity("Enemy", 200, 100, 50, 50, SDL_Color{255, 0, 0});
    }

    void SetRenderer(SDL_Renderer* renderer) {
        m_Renderer = renderer;
    }

    void OnUpdate() override {
        for (const auto& entity: m_Entities) {
            entity->Draw(m_Renderer, &m_Camera);
        }
    }

    void OnRender() override {
        m_Camera.DrawFrame(m_Renderer);
    }

    void OnEvent(const SDL_Event& event) override {
        if (event.type == SDL_KEYDOWN) {
            auto player = GetEntityByName("Player");
            if (!player) {
                return;
            }

            switch (event.key.keysym.sym) {
                case SDLK_w:
                    player->Move(0, -5);
                    break;
                case SDLK_s:
                    player->Move(0, 5);
                    break;
                case SDLK_a:
                    player->Move(-5, 0);
                    break;
                case SDLK_d:
                    player->Move(5, 0);
                    break;
            }
        }
    }

    std::shared_ptr<blew::Entity> GetEntityByName(const std::string& name) {
        for (auto& entity: m_Entities) {
            if (entity->GetName() == name) {
                return entity;
            }
            return nullptr;
        }
    }

    void AddEntity(const std::string& name, int x, int y, int w, int h, SDL_Color color) {
        m_Entities.emplace_back(std::make_shared<blew::Entity>(name, x, y, w, h, color));
    }

private:
    SDL_Renderer* m_Renderer = nullptr;
    std::vector<std::shared_ptr<blew::Entity>> m_Entities;
    blew::Camera m_Camera;
};