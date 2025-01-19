#pragma once

#include <iostream>
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