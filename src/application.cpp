//
// Created by caleb on 8/1/25.
//

#include "blew/application.h"

#include "blew/log.h"

namespace blew {

    Application::Application(const std::string& name)
    {
        m_Name = name;
        m_GameLayer = std::make_shared<GameLayer>();

        InitSDL();
        InitWindow();
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
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }

                m_GameLayer->OnEvent(event);
            }
            SDL_SetRenderDrawColor(renderer_ptr, 255, 0, 0, 255);
            SDL_RenderClear(renderer_ptr);
            SDL_RenderPresent(renderer_ptr);
        }

        SDL_DestroyRenderer(renderer_ptr);
        SDL_DestroyWindow(WindowPtr->GetSdlWindow());
        SDL_Quit();
    }

}