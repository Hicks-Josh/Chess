#include "Rook.h"

Rook::Rook(std::string color)
        : RestrictedPiece(color)
{
}

Rook::~Rook()
{
}

bool Rook::canMoveTo(Square &location) const
{
    Board& board = Board::getBoard();
    return board.isClearHorizontal(Piece::location(),location) ||
    board.isClearVertical(Piece::location(), location);
}

int Rook::value() const
{
    return 5;
}

void Rook::display(std::ostream &outStream) const
{
    outStream << color() << "R";
}
