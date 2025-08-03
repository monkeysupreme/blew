#pragma once

#include "blew/layer.h"
#include "blew/log.h"

#include <SDL2/SDL.h>

class InputLayer : public blew::Layer {
public:
    InputLayer() : Layer("InputLayer") {}

    void OnEvent(const SDL_Event& event) override {
        switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_w) {

                }
            default:
                break;
        }
    }

    void OnUpdate() override {}
};