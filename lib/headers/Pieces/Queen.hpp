#pragma once
#include "Piece.hpp"

class Queen : public Piece {
public:
    Queen(Color color, const unsigned int position);
    void move() override;

private:
};