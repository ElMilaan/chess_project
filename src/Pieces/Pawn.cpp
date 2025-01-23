#include "../lib/headers/Pieces/Pawn.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Pawn::Pawn(Color color)
    : Piece(color)
{
    symbol = "o";
    displacement.push_back(Displacement::FRONT);
    infinite_range = false;
};