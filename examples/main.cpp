#include "blew/blew.h"
#include "blew/layers/game_layer.h"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>

int main(int argc, char** argv) {
    // Logging
    blew::Logger::Init();

    blew::Run();
}