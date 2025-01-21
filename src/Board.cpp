#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(unsigned int dimension, unsigned int nb_pieces)
    : dimension(dimension), spaces(ImVector<Space>()), pieces(ImVector<Piece>()), nb_pieces(nb_pieces) {}

// SETTERS
void Board::set_dimension(unsigned int dimension) const
{
    dimension = dimension;
}

void Board::set_spaces(ImVector<Space> spaces) const
{
    spaces = spaces;
}

void Board::set_pieces(ImVector<Piece> pieces) const
{
    pieces = pieces;
}

// GETTERS
unsigned int Board::get_dimension() const
{
    return dimension;
}

ImVector<Space> Board::get_spaces() const
{
    return spaces;
}

ImVector<Piece> Board::get_pieces() const
{
    return pieces;
}

// METHODS

void Board::insert_space(const size_t pos, Color color)
{
    spaces.push_back(Space(static_cast<unsigned int>(pos), color));
}

void Board::fill_spaces()
{
    for (size_t i{1}; i <= dimension; i++)
    {
        for (size_t j{1}; j <= dimension; j++)
        {
            Color color = ((i + j) % 2 == 0) ? Color::WHITE : Color::BLACK;
            insert_space(i * dimension + j, color);
        }
    }
}

ImVec4 gen_color(const Color& color)
{
    return (color == Color::WHITE) ? ImVec4(1, 1, 1, 1) : ImVec4(0, 0, 0, 1);
}

void Board::init()
{
    fill_spaces();
}

void Board::render()
{
    // RENDER LES CASES

    unsigned int id{0};
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    for (const Space s : spaces)
    {
        // Définir la couleur de la case
        ImGui::PushStyleColor(ImGuiCol_Button, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, gen_color(s.get_color()));

        // Afficher un bouton carré de la taille de la case
        ImGui::PushID(id);
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