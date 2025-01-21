#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(unsigned int dimension)
    : dimension(dimension), spaces(ImVector<Space>()), pieces(ImVector<Piece>()), nb_w_pieces(0), nb_b_pieces(0) {}

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

void Board::display_pieces()
{
    for (Piece p : pieces)
    {
        std::cout << " | " << ((p.get_color() == Color::WHITE) ? "W" : "B") << "," << p.get_symbol() << " | ";
    }
}

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
              << "\nNb Black Pieces : " << nb_b_pieces
              << "\nPieces : \n";
    display_pieces();
    std::cout << "\nNb Spaces : " << pow(dimension, 2)
              << "\nSpaces :\n";
    display_spaces();
}

// METHODS

void Board::insert_space(const size_t pos, Color color, Piece* piece_ptr)
{
    spaces.push_back(Space(static_cast<unsigned int>(pos), color, piece_ptr));
}

void Board::fill_spaces()
{
    size_t piece_index{0};
    for (size_t i{1}; i <= dimension; i++)
    {
        for (size_t j{1}; j <= dimension; j++)
        {
            Color  color     = ((i + j) % 2 == 0) ? Color::WHITE : Color::BLACK;
            Piece* piece_ptr = nullptr;

            if (i == 1 || i == 2 || i == dimension || i == dimension - 1)
            {
                piece_ptr = &pieces[piece_index];
                piece_index++;
            }
            insert_space((i - 1) * dimension + j, color, piece_ptr);
        }
    }
}

void Board::insert_piece(PieceType type, Color color)
{
    switch (type)
    {
    case PieceType::KING:
        pieces.push_back(King(color));
        break;
    case PieceType::QUEEN:
        pieces.push_back(Queen(color));
        break;
    case PieceType::BISHOP:
        pieces.push_back(Bishop(color));
        break;
    case PieceType::ROOK:
        pieces.push_back(Rook(color));
        break;
    case PieceType::KNIGHT:
        pieces.push_back(Knight(color));
        break;
    case PieceType::PAWN:
        pieces.push_back(Pawn(color));
        break;
    }
}

void Board::fill_pieces()
{
    for (PieceType pt : PIECES_DISPOSITION)
    {
        insert_piece(pt, Color::BLACK);
        nb_w_pieces++;
    }
    for (int i{0}; i < dimension * 2; i++)
    {
        (i < dimension) ? insert_piece(PieceType::PAWN, Color::BLACK) : insert_piece(PieceType::PAWN, Color::WHITE);
    }

    for (auto it = PIECES_DISPOSITION.rbegin(); it != PIECES_DISPOSITION.rend(); it++)
    {
        insert_piece(*it, Color::WHITE);
        nb_w_pieces++;
    }
}

ImVec4 gen_color(const Color& color)
{
    return (color == Color::WHITE) ? ImVec4(0.87, 0.72, 0.53, 1) : ImVec4(0.47, 0.27, 0.2, 1);
}

void change_to_white_font(const unsigned int pos)
{
    if (pos == 17)
        ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
}

void Board::init()
{
    fill_pieces();
    fill_spaces();
}

void Board::render()
{
    // RENDER LES CASES
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    for (const Space s : spaces)
    {
        // Définir la couleur de la case
        ImGui::PushStyleColor(ImGuiCol_Button, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, gen_color(s.get_color()));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, gen_color(s.get_color()));

        change_to_white_font(s.get_position());

        // Afficher un bouton carré de la taille de la case
        ImGui::PushID(s.get_position());
        const char* space_label = (s.get_piece_ptr() == nullptr) ? "" : s.get_piece_ptr()->get_symbol();
        ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE});
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
}