#include "../lib/headers/Pieces/Queen.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Queen::Queen(Color color, const unsigned int position)
    : Piece(color, position)
{
    symbol         = "w";
    infinite_range = true;
};
