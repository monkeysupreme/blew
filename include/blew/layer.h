#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace blew {

    class Layer
    {
    public:
        explicit Layer(const std::string& name = "Layer") : m_Name(name)
        {}
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnRender() {}
        virtual void OnEvent(const SDL_Event& event) {}

        const std::string& GetName() const { return m_Name; }

    private:
        std::string m_Name;
    };

}