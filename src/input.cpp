//
// Created by caleb on 8/2/25.
//

#include "blew/input.h"

namespace blew {

    const uint8_t* Input::m_KeyState = nullptr;

    void Input::Init() {
        SDL_PumpEvents();
        m_KeyState = SDL_GetKeyboardState(nullptr);
    }

    void Input::Update() {
        SDL_PumpEvents();
        m_KeyState = SDL_GetKeyboardState(nullptr);
        // Mouse buttons...
    }

    bool Input::IsKeyPressed(SDL_Scancode key) {
        return m_KeyState[key];
    }
}