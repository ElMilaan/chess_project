#include "../lib/headers/Pieces/Piece.hpp"

Piece::Piece(const unsigned int position, Color color)
    : position(position), color(color) {}

Color Piece::get_color() const
{
    return color;
}

unsigned int Piece::get_position() const
{
    return position;
}

void Piece::set_color(Color color) const
{
    color = color;
}

void Piece::set_position(unsigned int position) const
{
    position = position;
}