#include "../lib/headers/App.hpp"

App::App(unsigned int board_size)
    : turn(Color::WHITE), board(Board(board_size)) {}

void App::init()
{
    board.init();
    ImGui::CreateContext();
    loadCustomFont();
};

void App::update()
{
    render();
};

void App::render()
{
    board.render();
};

void App::loadCustomFont()
{
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("../../lib/fonts/tt_usual.ttf", 64.0f);
}