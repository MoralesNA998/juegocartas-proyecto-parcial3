#include "Juego.h"
#include <ftxui/component/screen_interactive.hpp>

int main() {
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    Juego juego;
    screen.Loop(juego.Render());
    return 0;
}