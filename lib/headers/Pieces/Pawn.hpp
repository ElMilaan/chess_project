#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(Color color)
        : Piece(color)
    {
        symbol = "o";
    };

private:
};