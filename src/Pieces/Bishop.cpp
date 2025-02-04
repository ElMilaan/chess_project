#include "../lib/headers/Pieces/Bishop.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Bishop::Bishop(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "v";
    infinite_range = true;
};