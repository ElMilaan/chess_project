#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>

enum Color {
    WHITE,
    BLACK
};

class Space {
public:
    Space(ImVec2 position, Color color);
    void   set_posiiton(ImVec2 position);
    void   set_color(Color color);
    ImVec2 get_position();
    Color  get_color();

private:
    ImVec2 position;
    Color  color;
};