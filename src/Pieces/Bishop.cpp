#include "../lib/headers/Pieces/Bishop.hpp"
#include "../lib/headers/Pieces/Piece.hpp"

Bishop::Bishop(Color color)
    : Piece(color)
{
    symbol = "v";
    displacement.push_back(Displacement::DIAGONAL);
    infinite_range = true;
};