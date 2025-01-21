#pragma once
#include <iostream>
#include <quick_imgui/quick_imgui.hpp>
#include <vector>
#include "Pieces/Piece.hpp"
#include "Space.hpp"

class Board {
private:
    unsigned int    dimension;
    unsigned int    nb_pieces;
    ImVector<Space> spaces;
    ImVector<Piece> pieces;

public:
    static const unsigned int SPACE_SIZE{100};

    Board(unsigned int dimension, unsigned int nb_pieces);
    void            set_dimension(unsigned int dimension) const;
    void            set_spaces(ImVector<Space> spaces) const;
    void            set_pieces(ImVector<Piece> pieces) const;
    unsigned int    get_dimension() const;
    ImVector<Space> get_spaces() const;
    ImVector<Piece> get_pieces() const;

    void insert_space(const size_t pos, Color color);
    void fill_spaces();
    void fill_pieces();
    void init();
    void render();
};