#include "Bishop.h"

Bishop::Bishop(std::string color)
        : Piece(color)
{
}

Bishop::~Bishop()
{
}

bool Bishop::canMoveTo(Square &location) const
{
    return Board::getBoard().isClearDiagonal(Piece::location(), location);
}

int Bishop::value() const
{
    return 3;
}

void Bishop::display(std::ostream &outStream) const
{
    outStream << color() + "B";
}
