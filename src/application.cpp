//
// Created by caleb on 8/1/25.
//

#include "blew/application.h"

#include "blew/log.h"

namespace blew {

    Application::Application(const std::string& name)
    {
        m_Name = name;
        InitSDL();
        InitWindow();

        PushLayer(std::make_shared<InputLayer>());
        PushLayer(std::make_shared<GameLayer>());
    }

    Application::~Application()
    {
        delete WindowPtr;
    }

    void Application::InitSDL()
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            std::cerr << "Application::InitSDL(...): Error initializing SDL\n";
            exit(EXIT_FAILURE);
        }

        blew::Logger::Get()->info("Initialized SDL for application");
    }

    void Application::InitWindow()
    {
        WindowPtr = new Window(
            "",
            800,
            600
        );
    }

    void Application::Start()
    {
        WindowPtr->Show();

        bool running = true;
        SDL_Event event;

        SDL_Renderer* renderer_ptr = SDL_CreateRenderer(
                WindowPtr->GetSdlWindow(),
                -1,
                SDL_RENDERER_ACCELERATED
        );

        while (running)
        {
            Input::Update();

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }

                for (auto& layer : m_LayerStack)
                {
                    layer->OnEvent(event);
                    if (auto game_layer = std::dynamic_pointer_cast<GameLayer>(layer))
                    {
                        game_layer->SetRenderer(renderer_ptr);
                    }
                }
            }

            SDL_SetRenderDrawColor(renderer_ptr, 0, 0, 0, 255);
            SDL_RenderClear(renderer_ptr);

            for (auto& layer : m_LayerStack)
            {
                layer->OnUpdate();
                layer->OnRender();
            }

            SDL_RenderPresent(renderer_ptr);
        }

        SDL_DestroyRenderer(renderer_ptr);
        SDL_DestroyWindow(WindowPtr->GetSdlWindow());
        SDL_Quit();
    }

    void Application::PushLayer(const std::shared_ptr<Layer> &layer)
    {
        m_LayerStack.PushLayer(layer);
    }

}