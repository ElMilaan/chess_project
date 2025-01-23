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
        nb_b_pieces++;
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

void Board::set_space_style(const Color color)
{
    ImGui::PushStyleColor(ImGuiCol_Button, (color == Color::WHITE) ? colors.WHITE_SPACE : colors.BLACK_SPACE);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (color == Color::WHITE) ? colors.WHITE_SPACE_HOVERED : colors.BLACK_SPACE_HOVERED);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (color == Color::WHITE) ? colors.WHITE_SPACE_ACTIVE : colors.BLACK_SPACE_ACTIVE);
}

void Board::set_piece_style(Piece* piece_ptr, const char*& space_label)
{
    if (piece_ptr != nullptr)
    {
        (piece_ptr->get_color() == Color::WHITE) ? ImGui::GetStyle().Colors[ImGuiCol_Text] = colors.WHITE_PIECE
                                                 : ImGui::GetStyle().Colors[ImGuiCol_Text] = colors.BLACK_PIECE;
        space_label = piece_ptr->get_symbol();
    }
}

void Board::no_action_button(const char* space_label)
{
    ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE});
}

void Board::first_click_button(Space& s, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        selected_piece = s.get_piece_ptr();
        std::cout << "first click at : " << s.get_position() << " , " << selected_piece << "\n";
    }
}

void Board::second_click_button(Space& s, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        selected_piece = nullptr;
        std::cout << "second click at : " << s.get_position() << " , " << selected_piece << "\n";
    }
}

void Board::create_button(Space s, const char* space_label, Color turn)
{
    ImGui::PushID(s.get_position());

    if (s.get_piece_ptr() != nullptr && s.get_piece_ptr()->get_color() == turn)
    {
        first_click_button(s, space_label);
    }
    else if (selected_piece != nullptr)
    {
        second_click_button(s, space_label);
    }
    else
    {
        no_action_button(space_label);
    }

    ImGui::PopID();
}

void Board::init()
{
    selected_piece = nullptr;
    fill_pieces();
    fill_spaces();
}

void Board::render()
{
    // RENDER LES CASES

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    for (const Space s : spaces)
    {
        set_space_style(s.get_color());

        const char* space_label = "";
        set_piece_style(s.get_piece_ptr(), space_label);

        create_button(s, space_label, Color::WHITE);

        ImGui::PopStyleColor(3);

        if (s.get_position() % 8 != 0)
        {
            ImGui::SameLine();
        }
    }
    ImGui::PopStyleVar(1);
}