//
// Created by caleb on 8/2/25.
//

#include "blew/camera.h"

namespace blew {

    void Camera::SetPosition(int x, int y) {
        m_Position.x = x;
        m_Position.y = y;
    }

    void Camera::Move(int dx, int dy) {
        m_Position.x += dx;
        m_Position.y += dy;
    }

    SDL_Rect Camera::GetViewRect() const {
        return SDL_Rect{ m_Position.x, m_Position.y, m_Width, m_Height };
    }

    SDL_Rect Camera::WorldToScreen(const SDL_Rect& world_rect) const {
        return SDL_Rect{
            world_rect.x - m_Position.x,
            world_rect.y - m_Position.y,
            world_rect.w,
            world_rect.h
        };
    }

    void Camera::DrawFrame(SDL_Renderer* renderer) const {
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // gray
        SDL_Rect frame = {0, 0, m_Width, m_Height}; // viewport is always 0,0 in screen space
        SDL_RenderDrawRect(renderer, &frame);
    }

}