#pragma once

#include <SDL2/SDL.h>

namespace blew {

    class Camera {
    public:
        Camera(int x, int y, int width, int height)
                : m_Position({x, y}), m_Width(width), m_Height(height)
        {}

        void SetPosition(int x, int y);
        void Move(int dx, int dy);

        SDL_Rect GetViewRect() const;
        SDL_Rect WorldToScreen(const SDL_Rect& world_rect) const;

        void DrawFrame(SDL_Renderer* renderer) const;

    private:
        SDL_Point m_Position;
        int m_Width, m_Height;
    };

}