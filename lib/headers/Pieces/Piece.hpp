#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include "../utils.hpp"

enum Displacement {
    DIAGONAL,
    SIDES,
    FRONT,
    L
};

class Piece {
public:
    Piece(Color color);
    virtual ~Piece() = default;
    void        set_color(Color color) const;
    Color       get_color() const;
    const char* get_symbol() const;

protected:
    Color                     color;
    const char*               symbol;
    std::vector<Displacement> displacement;
    bool                      infinite_range;
};