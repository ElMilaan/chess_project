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
    unsigned int        dimension;
    unsigned int        nb_w_pieces;
    unsigned int        nb_b_pieces;
    std::vector<Piece*> spaces;
    Piece*              selected_piece;
    std::map<int, bool> possible_spaces;
    Color               turn;

public:
    static const unsigned int                  SPACE_SIZE{100};
    static const inline std::vector<PieceType> PIECES_DISPOSITION{ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};
    const ColorUI                              colors{};

    Board(unsigned int dimension);
    unsigned int get_dimension() const;
    Color        get_turn() const;
    void         set_dimension(unsigned int dimension) const;
    void         handle_turn();

    void display_spaces();

    void insert_piece(PieceType type, Color color, const unsigned int position);
    void fill_pieces();

    void init();
    void update();

    void set_space_style(Color color);
    void set_piece_style(Piece* piece_ptr, const char*& space_label);

    void no_action_button(const char* space_label);
    void first_click_button(size_t index, const char* space_label);
    void second_click_button(size_t index, const char* space_label);
    void create_button(size_t index, const char* space_label);
    void render();
};