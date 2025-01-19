#pragma once
#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include <vector>
#include "Pieces/Piece.hpp"
#include "Space.hpp"

class Board {
private:
    ImVec2             dimension;
    unsigned int       nb_pieces;
    std::vector<Space> spaces;
    std::vector<Piece> pieces;

public:
    Board(ImVec2 dimension, unsigned int nb_pieces);
    void               set_dimension(ImVec2 dimension);
    void               set_spaces(std::vector<Space> spaces);
    void               set_pieces(std::vector<Piece> pieces);
    ImVec2             get_dimension();
    std::vector<Space> get_spaces();
    std::vector<Piece> get_pieces();

    void insert_space(size_t pos_x, size_t pos_y, Color color);
    void fill_spaces();
    void init();
    void render();
};