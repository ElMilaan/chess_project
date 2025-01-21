#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include "../Space.hpp"

class Piece {
public:
    Piece(const unsigned int position, Color color);
    void         set_position(unsigned int position) const;
    void         set_color(Color color) const;
    unsigned int get_position() const;
    Color        get_color() const;

    // virtual void            can_move();
    // virtual ImVector<Space> possible_move();

private:
    unsigned int position;
    Color        color;
};