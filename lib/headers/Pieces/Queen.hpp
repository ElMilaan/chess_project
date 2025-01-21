#include "Piece.hpp"

class Queen : public Piece {
public:
    Queen(Color color)
        : Piece(color)
    {
        symbol = "w";
    };

private:
};