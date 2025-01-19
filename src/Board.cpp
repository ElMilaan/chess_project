#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(ImVec2 dimension, unsigned int nb_pieces)
    : dimension(dimension), spaces(std::vector<Space>()), pieces(std::vector<Piece>()), nb_pieces(nb_pieces) {}

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

void Board::insert_space(size_t pos_x, size_t pos_y, Color color)
{
    spaces.push_back(Space({static_cast<float>(pos_x), static_cast<float>(pos_y)}, color));
}

void Board::fill_spaces()
{
    for (size_t i{1}; i <= dimension.x; i++)
    {
        for (size_t j{1}; j <= dimension.y; j++)
        {
            (i * j % 2 == 1) ? insert_space(i, j, Color::WHITE)
                             : insert_space(i, j, Color::BLACK);
        }
    }
}

void Board::init()
{
    fill_spaces();
}

void Board::render()
{
    // RENDER LES CASES

    for (Space s : spaces)
    {
    }

    // RENDER LES PIECES

    // for(Piece p : pieces){
    //     p.render();
    // }
}