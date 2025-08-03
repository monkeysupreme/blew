//
// Created by caleb on 8/2/25.
//

#include "blew/entity.h"

namespace blew {

    void Entity::Draw(SDL_Renderer* renderer, const Camera* camera) const {
        SDL_Rect screen = { m_X, m_Y, m_Width, m_Height };
        if (camera) {
            screen = camera->WorldToScreen(screen);
        }

        SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
        SDL_RenderFillRect(renderer, &m_Rect);
    }

    void Entity::Move(int dx, int dy) {
        m_Rect.x += dx;
        m_Rect.y += dy;
    }

}