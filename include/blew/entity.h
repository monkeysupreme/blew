#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace blew {

    class Entity
    {
    public:
        Entity(const std::string &name,
               int x, int y,
               int w, int h,
               SDL_Color color)
                : m_Name(name), m_Rect({x, y, w, h}), m_Color(color)
        {}

        void Draw(SDL_Renderer *renderer) const;

        void Move(int dx, int dy);

        const std::string &GetName() const
        { return m_Name; }

        const SDL_Rect &GetRect() const
        { return m_Rect; }

        void SetColor(SDL_Color color)
        { m_Color = color; }

    private:
        std::string m_Name;
        SDL_Rect m_Rect;
        SDL_Color m_Color;
    };

}