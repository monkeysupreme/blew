//
// Created by caleb on 8/1/25.
//

#include "blew/window.h"

namespace blew {

    void Window::Show() {
        SDL_Window* window = SDL_CreateWindow(
                m_Title.c_str(),
                100, 100,
                m_Width, m_Height,
                SDL_WINDOW_SHOWN
        );

        if (!window) {
            std::cerr << "Window::Show(...): Error creating window\n";
            SDL_Quit();
            exit(EXIT_FAILURE);
        }

        m_Window = window;
    }

    SDL_Window* Window::GetSdlWindow() {
        if (!m_Window) {
            std::cerr << "Window::GetSdlWindow(...): Error fetching SDL window\n";
            SDL_Quit();
            exit(EXIT_FAILURE);
        }

        return m_Window;
    }

}