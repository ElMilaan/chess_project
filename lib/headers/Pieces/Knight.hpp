#pragma once
#include "Piece.hpp"

class Knight : public Piece {
public:
    Knight(Color color, const unsigned int position);
    void move() override;

private:
};