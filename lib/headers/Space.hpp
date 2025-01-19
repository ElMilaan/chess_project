#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>

class Space {
public:
    Space(ImVec2 position, ImVec4 color);
    void   set_posiiton(ImVec2 position);
    void   set_color(ImVec4 color);
    ImVec2 get_position();
    ImVec4 get_color();

private:
    ImVec2 position;
    ImVec4 color;
};