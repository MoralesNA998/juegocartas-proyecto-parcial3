#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();
    auto renderer = Renderer([] {
        return vbox({
            text("¡Hola, FTXUI!"),
            separator(),
            text("Presiona q para salir."),
        });
    });

    auto quit = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('q'))
            screen.Exit();
        return false;
    });

    screen.Loop(quit);
    return 0;
}