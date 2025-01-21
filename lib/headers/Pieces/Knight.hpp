#include "Piece.hpp"

class Knight : public Piece {
public:
    Knight(Color color)
        : Piece(color)
    {
        symbol = "m";
    };

private:
};