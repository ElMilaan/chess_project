#include "../lib/headers/Board.hpp"
#include <math.h>

Board::Board(unsigned int dimension)
    : dimension(dimension), spaces(std::vector<Piece*>(pow(dimension, 2), nullptr)), nb_w_pieces(0), nb_b_pieces(0), turn(WHITE) {}

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

void Board::display_spaces()
{
    int cpt{1};
    for (Piece* p : spaces)
    {
        if (p)
        {
            std::cout << " | " << p->get_position() << ", ";
            (p->get_color() == WHITE) ? std::cout << "W | " : std::cout << "B | ";
        }
        else
        {
            std::cout << " | EMP | ";
        }
        (cpt % 8 == 0) ? std::cout << "\n" : std::cout << "";
        cpt++;
    }
}

// METHODS

void Board::insert_piece(PieceType type, Color color, const unsigned int position)
{
    switch (type)
    {
    case PieceType::KING:
        spaces[position] = new King(color, position);
        break;
    case PieceType::QUEEN:
        spaces[position] = new Queen(color, position);
        break;
    case PieceType::BISHOP:
        spaces[position] = new Bishop(color, position);
        break;
    case PieceType::ROOK:
        spaces[position] = new Rook(color, position);
        break;
    case PieceType::KNIGHT:
        spaces[position] = new Knight(color, position);
        break;
    case PieceType::PAWN:
        spaces[position] = new Pawn(color, position);
        break;
    }
}

void Board::fill_pieces()
{
    size_t piece_index_start{0}, piece_index_end{(size_t)pow(dimension, 2) - 1};
    for (PieceType pt : PIECES_DISPOSITION)
    {
        insert_piece(pt, BLACK, piece_index_start);
        insert_piece(PAWN, BLACK, piece_index_start + dimension);
        insert_piece(pt, WHITE, piece_index_end);
        insert_piece(PAWN, WHITE, piece_index_end - dimension);
        nb_b_pieces++;
        nb_w_pieces++;
        piece_index_start++;
        piece_index_end--;
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
    if (piece_ptr)
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

void Board::first_click_button(size_t index, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        selected_piece = spaces[index];
        // std::cout << "cases possibles : " << possible_spaces.size();
        std::cout << "selected piece : " << selected_piece << "\n";
    }
}

void Board::second_click_button(size_t index, const char* space_label)
{
    if (ImGui::Button(space_label, {SPACE_SIZE, SPACE_SIZE}))
    {
        // if (possible_spaces.contains(s.get_position()))
        // {
        std::cout << "target piece : " << spaces[index] << "\n";
        selected_piece->move(spaces, index);
        selected_piece = nullptr;
        handle_turn();
        // }
    }
}

void Board::create_button(size_t index, const char* space_label)
{
    if (spaces[index] && spaces[index]->get_color() == turn)
        first_click_button(index, space_label);
    else
        (!selected_piece) ? no_action_button(space_label) : second_click_button(index, space_label);
}

void Board::init()
{
    selected_piece = nullptr;
    fill_pieces();
    display_spaces();
}

void Board::update()
{
}

void Board::render()
{
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    Color        color{WHITE};
    unsigned int id{1};
    for (int i{0}; i < spaces.size(); i++)
    {
        set_space_style(color);

        const char* space_label = "";
        set_piece_style(spaces[i], space_label);

        ImGui::PushID(id);
        create_button(i, space_label);
        ImGui::PopID();

        ImGui::PopStyleColor(3);

        if (id % 8 != 0)
        {
            ImGui::SameLine();
            color = (color == WHITE) ? BLACK : WHITE;
        }

        id++;
    }
    ImGui::PopStyleVar(1);
}