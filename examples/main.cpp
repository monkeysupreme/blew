#include "blew/blew.h"
#include "blew/layers/game_layer.h"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>

blew::Application* app = nullptr;

void StartGame(Fl_Widget* widget, void* data)
{
    if (!app)
    {
        app = new blew::Application("Blew Game Example");
        app->Start();
        delete app;
        app = nullptr;
    }
}

int main(int argc, char** argv) {
    // Logginga
    blew::Logger::Init();

    Fl_Window* win = new Fl_Window(300, 200, "FLTK + Blew");
    Fl_Button* btn = new Fl_Button(100, 80, 100, 40, "Start Game");
    btn->callback(StartGame);

    win->end();
    win->show(argc, argv);

    return Fl::run();
}