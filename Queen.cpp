#include "Queen.h"

Queen::Queen(std::string color)
        : Piece(color)
{
}

Queen::~Queen()
{
}

bool Queen::canMoveTo(Square &location) const
{
    Board& board = Board::getBoard();
    return board.isClearVertical(Piece::location(), location) ||
    board.isClearHorizontal(Piece::location(), location) ||
    board.isClearDiagonal(Piece::location(), location);
}

int Queen::value() const
{
    return 9;
}

void Queen::display(std::ostream &outStream) const
{
    outStream << color() + "Q";
}
