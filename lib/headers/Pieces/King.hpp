#include "Piece.hpp"

class King : public Piece {
public:
    King(Color color)
        : Piece(color)
    {
        symbol = "l";
    };

private:
};