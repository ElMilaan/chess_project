#include "../lib/headers/Pieces/King.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

King::King(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "l";
    infinite_range = false;
};

void King::move()
{
}