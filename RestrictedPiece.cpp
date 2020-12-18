#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(std::string color)
        : Piece(color)
{
}

RestrictedPiece::~RestrictedPiece()
{
}

bool RestrictedPiece::hasMoved() const
{
    return _moved;
}

bool RestrictedPiece::moveTo(Player &byPlayer, Square &to)
{
    // checks for a valid move
    bool didMove = Piece::moveTo(byPlayer, to);
    // if valid move, set _moved to true
    if (didMove)
    {
        _moved = true;
    }
    return didMove;
}
