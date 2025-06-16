PROYECTO := programa
CXX := c++
CXXFLAGS := -std=c++17 -Iinclude -IFTXUI/include 
EXE := bin/$(PROYECTO)

SRC := src/main.cpp src/Juego.cpp

FTXUI_SRC := FTXUI/src/ftxui/component/component.cpp FTXUI/src/ftxui/component/screen_interactive.cpp FTXUI/src/ftxui/component/event.cpp FTXUI/src/ftxui/screen/screen.cpp FTXUI/src/ftxui/screen/terminal.cpp FTXUI/src/ftxui/dom/node.cpp FTXUI/src/ftxui/dom/text.cpp FTXUI/src/ftxui/dom/flexbox.cpp FTXUI/src/ftxui/dom/size.cpp

ALL_SRC := $(SRC) $(FTXUI_SRC)

$(EXE): $(ALL_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE)