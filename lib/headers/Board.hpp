#pragma once
#include <iostream>
#include <map>
#include <quick_imgui/quick_imgui.hpp>
#include <vector>
#include "Pieces/Piece.hpp"
#include "Space.hpp"

enum PieceTypes {
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
};

class Board {
private:
    unsigned int    dimension;
    unsigned int    nb_w_pieces;
    unsigned int    nb_b_pieces;
    ImVector<Space> spaces;
    ImVector<Piece> pieces;

public:
    static const unsigned int                              SPACE_SIZE{100};
    static const unsigned int                              NB_W_PIECES{16};
    static const unsigned int                              NB_B_PIECES{16};
    static const inline std::map<PieceTypes, unsigned int> PIECES_COUNT{
        {KING, 1},
        {QUEEN, 1},
        {BISHOP, 2},
        {ROOK, 2},
        {KNIGHT, 2},
        {PAWN, 8}
    };

    Board(unsigned int dimension);
    void         set_dimension(unsigned int dimension) const;
    unsigned int get_dimension() const;

    void display_spaces();
    void debug();

    void insert_space(const size_t pos, Color color);
    void fill_spaces();
    void fill_pieces();
    void init();
    void render();
};