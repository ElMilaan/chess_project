#include "../lib/headers/Board.hpp"

Space::Space(ImVec2 position, ImVec4 color)
    : position(position), color(color) {}

void Space::set_posiiton(ImVec2 position)
{
    position = position;
}
void Space::set_color(ImVec4 color)
{
    color = color;
}
ImVec2 Space::get_position()
{
    return position;
}
ImVec4 Space::get_color()
{
    return color;
}