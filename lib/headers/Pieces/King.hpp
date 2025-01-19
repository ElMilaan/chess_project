#include "Piece.hpp"

class King : public Piece {
public:
    King(ImVec2 position, ImVec4 color);
    bool is_mate;
    void move(ImVec2 new_position);

private:
    bool is_mate;
};