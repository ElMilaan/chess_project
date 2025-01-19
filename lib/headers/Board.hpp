#pragma once
#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include <vector>
#include "Piece.hpp"
#include "Space.hpp"

class Board {
private:
    ImVec2             dimension;
    std::vector<Space> spaces;
    std::vector<Piece> pieces;

public:
    Board(ImVec2 dimension);
    void               set_dimension(ImVec2 dimension);
    void               set_spaces(std::vector<Space> spaces);
    void               set_pieces(std::vector<Piece> pieces);
    ImVec2             get_dimension();
    std::vector<Space> get_spaces();
    std::vector<Piece> get_pieces();
    void               init();
};