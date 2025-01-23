#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include "Pieces/Piece.hpp"

class Space {
public:
    Space(const unsigned int position, Color color, Piece* piece_ptr);
    void         set_piece_ptr(Piece* piece_ptr);
    unsigned int get_position() const;
    Color        get_color() const;
    Piece*       get_piece_ptr() const;

    void display(const unsigned int dim) const;
    bool is_border(const unsigned int dim) const;

    void move_piece(Space& dest);

private:
    unsigned int position;
    Color        color;
    Piece*       piece_ptr;
};