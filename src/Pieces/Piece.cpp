#include "../lib/headers/Pieces/Piece.hpp"

Piece::Piece(Color color)
    : color(color) {}

Color Piece::get_color() const
{
    return color;
}

// unsigned int Piece::get_position() const
// {
//     return position;
// }

const char* Piece::get_symbol() const
{
    return symbol;
}

void Piece::set_color(Color color) const
{
    color = color;
}

// void Piece::set_position(unsigned int position) const
// {
//     position = position;
// }