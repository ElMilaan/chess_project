#pragma once

#include <iostream>
#include "Board.hpp"

class App {
public:
    App(unsigned int board_size);
    void init();
    void update();
    void render();

    void loadCustomFont();

private:
    Board board;
    Color turn;
};