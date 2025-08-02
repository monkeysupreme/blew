#pragma once

#include "blew/layer.h"
#include "blew/log.h"

#include <SDL2/SDL.h>

class InputLayer : public blew::Layer
{
public:
    InputLayer() : Layer("InputLayer")
    {}

    void OnEvent(const SDL_Event& event) override
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                blew::Logger::Get()->info("Key Pressed: {}", SDL_GetKeyName(event.key.keysym.sym));
            default:
                break;
        }
    }

    void OnUpdate() override
    {}
};