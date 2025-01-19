#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>

class Piece {
public:
    Piece(ImVec2 position, ImVec4 color);
    void   set_position(ImVec2 position);
    void   set_color(ImVec4 color);
    ImVec2 get_position();
    ImVec4 get_color();

    void         move(ImVec2 new_position);
    virtual void possibleSpaces();

private:
    ImVec2 position;
    ImVec4 color;
};