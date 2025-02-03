#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(Color color, const unsigned int position);
    void move() override;

private:
};