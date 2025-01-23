#include "../lib/headers/Pieces/Rook.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Rook::Rook(Color color)
    : Piece(color)
{
    symbol = "t";
    displacement.push_back(Displacement::SIDES);
    infinite_range = true;
};