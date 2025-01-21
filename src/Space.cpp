#include <cmath>
#include "../lib/headers/Board.hpp"

Space::Space(const unsigned int position, Color color, Piece* piece)
    : position(position), color(color), piece(piece) {}

void Space::set_position(unsigned int position) const
{
    position = position;
}
void Space::set_color(Color color) const
{
    color = color;
}
unsigned int Space::get_position() const
{
    return position;
}
Color Space::get_color() const
{
    return color;
}

void Space::display(const unsigned int dim) const
{
    std::cout << " | " << position << "," << ((color == Color::WHITE) ? "W" : "B") << ((is_border(dim)) ? ",yes" : ",no") << ((position % 8 == 0) ? "|\n" : "|");
}

bool Space::is_border(const unsigned int dim) const
{
    return (position <= dim || position >= pow(dim, 2) - dim || position % dim == 0 || position % dim == 1);
}