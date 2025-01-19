#include "../lib/headers/Board.hpp"

Board::Board(ImVec2 dimension)
    : dimension(dimension) {}

// SETTERS
void Board::set_dimension(ImVec2 dimension)
{
    dimension = dimension;
}

void Board::set_spaces(std::vector<Space> spaces)
{
    spaces = spaces;
}

void Board::set_pieces(std::vector<Piece> pieces)
{
    pieces = pieces;
}

// GETTERS
ImVec2 Board::get_dimension()
{
    return dimension;
}

std::vector<Space> Board::get_spaces()
{
    return spaces;
}

std::vector<Piece> Board::get_pieces()
{
    return pieces;
}

// METHODS
