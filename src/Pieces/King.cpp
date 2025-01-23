#include "../lib/headers/Pieces/King.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

King::King(Color color)
    : Piece(color)
{
    symbol = "l";
    displacement.push_back(Displacement::DIAGONAL);
    displacement.push_back(Displacement::SIDES);
    infinite_range = false;
};