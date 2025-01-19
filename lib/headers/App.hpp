#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include "Board.hpp"

class App {
public:
    App();
    void init();
    void update();
    void render();

private:
    Board board;
};