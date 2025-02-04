#include "../lib/headers/Pieces/Rook.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Rook::Rook(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "t";
    infinite_range = true;
};