#pragma once
#include <iostream>
#include <map>
#include <quick_imgui/quick_imgui.hpp>
#include <vector>
#include "Pieces/Bishop.hpp"
#include "Pieces/King.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Piece.hpp"
#include "Pieces/Queen.hpp"
#include "Pieces/Rook.hpp"
#include "Space.hpp"

enum PieceType {
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
    Space*          selected_space;

public:
    static const unsigned int                  SPACE_SIZE{100};
    static const inline std::vector<PieceType> PIECES_DISPOSITION{ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};
    const ColorUI                              colors{};

    Board(unsigned int dimension);
    void         set_dimension(unsigned int dimension) const;
    unsigned int get_dimension() const;

    void display_pieces();
    void display_spaces();
    void debug();

    void insert_space(const size_t pos, Color color, Piece* piece);
    void insert_piece(PieceType type, Color color);
    void fill_spaces();
    void fill_pieces();

    void init();

    void set_space_style(Color color);
    void set_piece_style(Piece* piece_ptr, const char*& space_label);

    void no_action_button(const char* space_label);
    void first_click_button(Space* s, const char* space_label);
    void second_click_button(Space* s, const char* space_label);
    void create_button(Space* s, const char* space_label, Color turn);
    void render();
};