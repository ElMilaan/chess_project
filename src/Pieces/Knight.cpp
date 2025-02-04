#include "../lib/headers/Pieces/Knight.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Knight::Knight(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "m";
    infinite_range = false;
};
