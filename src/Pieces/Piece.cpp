#include "../lib/headers/Pieces/Piece.hpp"
#include <math.h>

Piece::Piece(Color color, const unsigned int position)
    : color(color), position(position) {}

// GETTERS

Color Piece::get_color() const
{
    return color;
}

const char* Piece::get_symbol() const
{
    return symbol;
}

unsigned int Piece::get_position() const
{
    return position;
}

// SETTERS

void Piece::set_color(Color color) const
{
    color = color;
}

// METHODS

bool Piece::is_border(const unsigned int dim) const
{
    return (position <= dim || position >= pow(dim, 2) - dim || position % dim == 0 || position % dim == 1);
}

bool Piece::is_infinite_range() const
{
    return infinite_range;
}

void Piece::move() {}