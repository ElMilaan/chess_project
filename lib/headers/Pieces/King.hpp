#pragma once
#include "Piece.hpp"

class King : public Piece {
public:
    King(Color color, const unsigned int position);
    void move() override;

private:
};