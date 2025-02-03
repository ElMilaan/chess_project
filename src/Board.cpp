#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(unsigned int dimension)
    : dimension(dimension), pieces(ImVector<Piece>()), nb_w_pieces(0), nb_b_pieces(0), turn(WHITE) {}

// SETTERS
void Board::set_dimension(unsigned int dimension) const
{
    dimension = dimension;
}

void Board::handle_turn()
{
    (turn == WHITE)
        ? turn = BLACK
        : turn = WHITE;
}

// GETTERS
unsigned int Board::get_dimension() const
{
    return dimension;
}

Color Board::get_turn() const
{
    return turn;
}
// DEBUG

void Board::display_pieces()
{
    for (const Piece& p : pieces)
    {
        std::cout << " | " << ((p.get_color() == WHITE) ? "W" : "B") << "," << p.get_symbol() << " | ";
    }
}

void Board::debug()
{
    std::cout << "Nb White Pieces : " << nb_w_pieces
              << "\nNb Black Pieces : " << nb_b_pieces
              << "\nPieces : \n";
    display_pieces();
}

// METHODS

void Board::insert_piece(PieceType type, Color color, const unsigned int position)
{
    switch (type)
    {
    case PieceType::KING:
        pieces.push_back(King(color, position));
        break;
    case PieceType::QUEEN:
        pieces.push_back(Queen(color, position));
        break;
    case PieceType::BISHOP:
        pieces.push_back(Bishop(color, position));
        break;
    case PieceType::ROOK:
        pieces.push_back(Rook(color, position));
        break;
    case PieceType::KNIGHT:
        pieces.push_back(Knight(color, position));
        break;
    case PieceType::PAWN:
        pieces.push_back(Pawn(color, position));
        break;
    }
}

void Board::fill_pieces()
{
    for (size_t i{0}; i < dimension; i++)
    {
        for (PieceType pt : PIECES_DISPOSITION)
        {
            insert_piece(pt, BLACK, i);
            insert_piece(PAWN, BLACK, i + dimension);
            nb_b_pieces++;
        }
    }

    for (size_t i{(size_t)pow(dimension, 2) - 1}; i > (size_t)pow(dimension, 2) - dimension; i--)
    {
        for (auto it = PIECES_DISPOSITION.rbegin(); it != PIECES_DISPOSITION.rend(); it++)
        {
            insert_piece(*it, WHITE, i);
            insert_piece(PAWN, WHITE, i - dimension);
            nb_w_pieces++;
        }
    }
}

void Board::fill_spaces()
{
    for (int i{0}; i < pow(dimension, 2); i++)
    {
        if (i < pieces.size())
        {
            spaces.push_back(&pieces[i]);
        }
        else
        {
            spaces.push_back(nullptr);
        }
    }
}

void Board::set_space_style(const Color color)
{
    ImGui::PushStyleColor(ImGuiCol_Button, (color == WHITE) ? colors.WHITE_SPACE : colors.BLACK_SPACE);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (color == WHITE) ? colors.WHITE_SPACE_HOVERED : colors.BLACK_SPACE_HOVERED);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (color == WHITE) ? colors.WHITE_SPACE_ACTIVE : colors.BLACK_SPACE_ACTIVE);
}

void Board::set_piece_style(Piece* piece_ptr, const char*& space_label)
{
    if (piece_ptr != nullptr)
    {
        (piece_ptr->get_color() == WHITE) ? ImGui::GetStyle().Colors[ImGuiCol_Text] = colors.WHITE_PIECE
                                          : ImGui::GetStyle().Colors[ImGuiCol_Text] = colors.BLACK_PIECE;
        space_label = piece_ptr->get_symbol();
    }
}
void Board::no_action_button(const char* space_label)
{
    ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE});
}

void Board::first_click_button(Piece*& p, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        selected_piece = p;
        std::cout << "cases possibles : " << possible_spaces.size();
    }
}

void Board::second_click_button(Piece*& p, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        // if (possible_spaces.contains(s.get_position()))
        // {
        selected_piece->move();
        selected_piece = nullptr;
        handle_turn();
        // }
    }
}

void Board::create_button(Piece*& p, const char* space_label)
{
    ImGui::PushID(p->get_position());

    if (p && p->get_color() == turn)
        first_click_button(p, space_label);
    else
        (!selected_piece) ? no_action_button(space_label) : second_click_button(p, space_label);

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
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    for (Piece* p : spaces)
    {
        // set_space_style(p->get_position());

        const char* space_label = "";
        set_piece_style(p, space_label);

        create_button(p, space_label);

        // ImGui::PopStyleColor(1);

        if (p->get_position() % 8 != 0)
        {
            ImGui::SameLine();
        }
    }
    ImGui::PopStyleVar(1);
}