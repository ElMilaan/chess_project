#include <imgui.h>
#include <fstream>
#include <iostream>
#include "../lib/headers/App.hpp"
#include "quick_imgui/quick_imgui.hpp"

int main()
{
    App* app = new App(8);
    app->init();
    quick_imgui::loop("Chess", [&]() {}, [&]() {

        ImGui::Begin("Board");

        app->render();

        ImGui::End(); });
}