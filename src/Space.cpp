#include "../lib/headers/Board.hpp"

Space::Space(ImVec2 position, Color color)
    : position(position), color(color) {}

void Space::set_posiiton(ImVec2 position)
{
    position = position;
}
void Space::set_color(Color color)
{
    color = color;
}
ImVec2 Space::get_position()
{
    return position;
}
Color Space::get_color()
{
    return color;
}