#include <quick_imgui/quick_imgui.hpp>

enum Color {
    WHITE,
    BLACK
};

struct ColorUI {
    ImVec4 WHITE_SPACE{0.87f, 0.72f, 0.53f, 1.0f};
    ImVec4 WHITE_SPACE_HOVERED{0.79f, 0.64f, 0.45f, 1.0f};
    ImVec4 WHITE_SPACE_ACTIVE{0.73f, 0.58f, 0.40f, 1.0f};

    ImVec4 BLACK_SPACE{0.47f, 0.27f, 0.20f, 1.0f};
    ImVec4 BLACK_SPACE_HOVERED{0.39f, 0.19f, 0.12f, 1.0f};
    ImVec4 BLACK_SPACE_ACTIVE{0.34f, 0.14f, 0.07f, 1.0f};

    ImVec4 WHITE_PIECE{1.0f, 1.0f, 1.0f, 1.0f};
    ImVec4 BLACK_PIECE{0.0f, 0.0f, 0.0f, 1.0f};
};