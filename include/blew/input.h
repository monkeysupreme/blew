#pragma once

#include <stdint.h>

#include <SDL2/SDL.h>

namespace blew {

    class Input {
    public:
        static void Init();

        static void Update();

        static bool IsKeyPressed(SDL_Scancode key);

    private:
        static const uint8_t* m_KeyState;
    };

}