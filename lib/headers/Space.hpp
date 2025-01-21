#pragma once

#include <iostream>
#include <quick_imgui/quick_imgui.hpp>

enum Color {
    WHITE,
    BLACK
};

class Space {
public:
    Space(const unsigned int position, Color color);
    void         set_position(const unsigned int position) const;
    void         set_color(Color color) const;
    unsigned int get_position() const;
    Color        get_color() const;

private:
    unsigned int position;
    Color        color;
};