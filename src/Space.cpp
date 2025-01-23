#include <cmath>
#include "../lib/headers/Board.hpp"

Space::Space(const unsigned int position, Color color, Piece* piece_ptr)
    : position(position), color(color), piece_ptr(piece_ptr) {}

// GETTERS

unsigned int Space::get_position() const
{
    return position;
}
Color Space::get_color() const
{
    return color;
}

Piece* Space::get_piece_ptr() const
{
    return piece_ptr;
}

// SETTERS

void Space::set_piece_ptr(Piece* piece_ptr)
{
    piece_ptr = piece_ptr;
}

// UTILS

void Space::display(const unsigned int dim) const
{
    std::cout << " | " << position << "," << ((color == Color::WHITE) ? "W" : "B") << ((is_border(dim)) ? ",yes" : ",no") << ((position % 8 == 0) ? "|\n" : "|");
}

bool Space::is_border(const unsigned int dim) const
{
    return (position <= dim || position >= pow(dim, 2) - dim || position % dim == 0 || position % dim == 1);
}

// GAME

void Space::move_piece(Space& dest)
{
    dest.set_piece_ptr(piece_ptr);
    piece_ptr = nullptr;
}