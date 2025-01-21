#include "Piece.hpp"

class Bishop : public Piece {
public:
    Bishop(Color color)
        : Piece(color)
    {
        symbol = "v";
    };

private:
};