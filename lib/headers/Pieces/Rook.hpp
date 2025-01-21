#include "Piece.hpp"

class Rook : public Piece {
public:
    Rook(Color color)
        : Piece(color)
    {
        symbol = "t";
    };

private:
};