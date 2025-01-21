#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(unsigned int dimension)
    : dimension(dimension), spaces(ImVector<Space>()), pieces(ImVector<Piece>()), nb_w_pieces(NB_W_PIECES), nb_b_pieces(NB_B_PIECES) {}

// SETTERS
void Board::set_dimension(unsigned int dimension) const
{
    dimension = dimension;
}

// GETTERS
unsigned int Board::get_dimension() const
{
    return dimension;
}

// DEBUG

void Board::display_spaces()
{
    for (Space s : spaces)
    {
        s.display(dimension);
    }
}

void Board::debug()
{
    std::cout << "Nb White Pieces : " << nb_w_pieces
              << "Nb Black Pieces : " << nb_b_pieces
              << "\nNb Spaces : " << pow(dimension, 2);
    std::cout << "\nSpaces :\n";
    display_spaces();
}

// METHODS

void Board::insert_space(const size_t pos, Color color)
{
    spaces.push_back(Space(static_cast<unsigned int>(pos), color, nullptr));
}

void Board::fill_spaces()
{
    for (size_t i{1}; i <= dimension; i++)
    {
        for (size_t j{1}; j <= dimension; j++)
        {
            Color color = ((i + j) % 2 == 0) ? Color::WHITE : Color::BLACK;
            insert_space((i - 1) * dimension + j, color);
        }
    }
}

void Board::fill_pieces()
{
    for (auto p : PIECES_COUNT)
    {
        for (auto p : PIECES_COUNT)
        {
            for (size_t i{0}; i < p.second; i++)
            {
                // pieces.push_back();
            }
        }
    }
}

ImVec4 gen_color(const Color& color)
{
    return (color == Color::WHITE) ? ImVec4(0.87, 0.72, 0.53, 1) : ImVec4(0.47, 0.27, 0.2, 1);
}

void Board::init()
{
    fill_spaces();
}

void Board::render()
{
    // RENDER LES CASES
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    for (const Space s : spaces)
    {
        // Définir la couleur de la case
        ImGui::PushStyleColor(ImGuiCol_Button, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, gen_color(s.get_color()));

        // Afficher un bouton carré de la taille de la case
        ImGui::PushID(s.get_position());
        ImGui::Button("", {SPACE_SIZE, SPACE_SIZE});
        ImGui::PopID();

        // Restaurer les couleurs précédentes
        ImGui::PopStyleColor(3);

        // Ajout d'un espace pour coller les cases entre elles
        if (s.get_position() % 8 != 0)
        {
            ImGui::SameLine();
        }
    }
    ImGui::PopStyleVar(1);

    // RENDER LES PIECES

    // for(Piece p : pieces){
    //     p.render();
    // }
}