#pragma once

#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>

namespace blew {

    class Window
    {
    public:
        Window(const std::string& title, int width, int height)
               : m_Title(title),
                m_Width(width),
                m_Height(height)
        {}

        void Show();

        SDL_Window* GetSdlWindow();

    private:
        std::string m_Title;

        int m_Width;
        int m_Height;

        SDL_Window* m_Window;
    };

}