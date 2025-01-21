#include "../lib/headers/Board.hpp"

Space::Space(const unsigned int position, Color color)
    : position(position), color(color) {}

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