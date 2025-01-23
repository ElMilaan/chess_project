#include "../lib/headers/Pieces/Knight.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Knight::Knight(Color color)
    : Piece(color)
{
    symbol = "m";
    displacement.push_back(Displacement::L);
    infinite_range = false;
};