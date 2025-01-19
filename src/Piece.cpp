#include "../lib/headers/Pieces/Piece.hpp"

Piece::Piece(ImVec2 position, ImVec4 color)
    : position(position), color(color) {}

ImVec4 Piece::get_color()
{
    return color;
}

ImVec2 Piece::get_position()
{
    return position;
}

void Piece::set_color(ImVec4 color)
{
    this->color = color;
}

void Piece::set_position(ImVec2 position)
{
    this->position = position;
}