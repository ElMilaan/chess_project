#include <imgui.h>
#include <fstream>
#include <iostream>
#include "../lib/headers/App.hpp"
#include "quick_imgui/quick_imgui.hpp"

void loadCustomFont()
{
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("C:/Users/Milan/Desktop/Travail/1 - IMAC/A2/Prog/S4/chess_project/lib/fonts/tt_usual.ttf", 48.0f);
}

int main()
{
    float value{0.f};
    Board board(8);
    board.init();
    board.debug();

    ImGui::CreateContext();

    loadCustomFont();

    quick_imgui::loop("Chess", [&]() {}, [&]() {

        ImGui::Begin("Board");

        board.render();

        ImGui::End(); });
}

// ImGui::PushID(2); // When some ImGui items have the same label (for exemple the next two buttons are labeled "Yo") ImGui needs you to specify an ID so that it can distinguish them. It can be an int, a pointer, a string, etc.
//                   // You will definitely run into this when you create a button for each of your chess pieces, so remember to give them an ID!
// if (ImGui::Button("Yo", ImVec2{50.f, 50.f}))
//     std::cout << "Clicked button 2\n";
// ImGui::PopID(); // Then pop the id you pushed after you created the widget

// ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{1.f, 0.f, 0.f, 1.f}); // Changes the color of all buttons until we call ImGui::PopStyleColor(). There is also ImGuiCol_ButtonActive and ImGuiCol_ButtonHovered

// ImGui::SameLine(); // Draw the next ImGui widget on the same line as the previous one. Otherwise it would be below it

// ImGui::PopStyleColor();