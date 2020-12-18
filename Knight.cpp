#include "Knight.h"

Knight::Knight(std::string color)
        : Piece(color)
{
}

Knight::~Knight()
{
}

bool Knight::canMoveTo(Square &location) const
{
    int pieceLocationX = Piece::location().getX(),
    pieceLocationY =Piece::location().getY(),
    goalX = location.getX(), goalY = location.getY();
    bool validMove = true;

    // check for horizontal movement
    if (std::abs(pieceLocationX - goalX) == 1)
    {
        if (std::abs(pieceLocationY - goalY) != 2)
        {
            validMove = false;
        }
    }
    // check for vertical movement
    else if (std::abs(pieceLocationY - goalY) == 1)
    {
        if (std::abs(pieceLocationX - goalX) != 2)
        {
            validMove = false;
        }
    }
    // if not those base cases, then the move is invalid
    else
    {
        validMove = false;
    }
    return validMove;
}

int Knight::value() const
{
    return 3;
}

void Knight::display(std::ostream &outStream) const
{
    outStream << color() + "N";
}
