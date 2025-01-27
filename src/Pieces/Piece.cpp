#include "../lib/headers/Pieces/Piece.hpp"

Piece::Piece(Color color)
    : color(color) {}

Color Piece::get_color() const
{
    return color;
}

const char* Piece::get_symbol() const
{
    return symbol;
}

void Piece::set_color(Color color) const
{
    color = color;
}