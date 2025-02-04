#include "../lib/headers/Pieces/Pawn.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Pawn::Pawn(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "o";
    infinite_range = false;
};