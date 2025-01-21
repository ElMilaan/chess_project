#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>

enum Color {
    WHITE,
    BLACK
};

class Piece {
public:
    Piece(Color color, char symbol);
    virtual ~Piece() = default;
    // void         set_position(unsigned int position) const;
    void set_color(Color color) const;
    // unsigned int get_position() const;
    Color get_color() const;
    char  get_symbol() const;

    virtual void can_move() const = 0;
    // virtual ImVector<Space> possible_move() const = 0;

private:
    // unsigned int position;
    Color color;
    char  symbol;
};