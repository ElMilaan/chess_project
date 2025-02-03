#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include "../utils.hpp"

class Piece {
public:
    Piece(Color color, const unsigned int position);
    virtual ~Piece() = default;

    void set_color(Color color) const;

    Color        get_color() const;
    const char*  get_symbol() const;
    unsigned int get_position() const;
    bool         is_infinite_range() const;

    bool is_border(const unsigned int dim) const;

    virtual void move();

protected:
    unsigned int position;
    Color        color;
    const char*  symbol;
    bool         infinite_range;
};