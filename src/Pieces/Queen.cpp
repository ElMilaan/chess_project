#include "../lib/headers/Pieces/Queen.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Queen::Queen(Color color)
    : Piece(color)
{
    symbol = "w";
    displacement.push_back(Displacement::DIAGONAL);
    displacement.push_back(Displacement::SIDES);
    infinite_range = true;
};