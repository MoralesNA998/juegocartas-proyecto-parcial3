CXX := /c/msys64/mingw64/bin/g++.exe

CXXFLAGS := -std=c++17 -Wall -Iinclude -IC:/msys64/mingw64/include

LDFLAGS := -LC:/msys64/mingw64/lib -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR := src
SOURCES := $(SRCDIR)/main.cpp $(SRCDIR)/Carta.cpp $(SRCDIR)/Mazo.cpp $(SRCDIR)/Tablero.cpp $(SRCDIR)/Juego.cpp
TARGET := programa

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)