#include "Piece.hpp"

class King : public Piece {
public:
    King(ImVec2 position, ImVec4 color);

private:
    bool is_mate;
};