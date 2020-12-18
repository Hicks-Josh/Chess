#include "Pawn.h"
#include "Queen.h"

Pawn::Pawn(std::string color)
        : RestrictedPiece(color)
{
}

Pawn::~Pawn()
{
}

bool Pawn::canMoveTo(Square &location) const
{
    bool validMove = true;
    if (!_delegate)
    {
        int fromX = Piece::location().getX(), toX = location.getX(),
        fromY = Piece::location().getY(), toY = location.getY(), direction = 1,
        specialDirection = 2;

        if (color() == "B")
        {
            direction = -1;
            specialDirection *= -1;
        }

        // check for capture
        if (std::abs(fromX - toX) == 1)
        {
            if (location.occupied())
            {
                // if capturing own piece
                if (location.occupiedBy().color() == color())
                {
                    validMove = false;
                }
            }
        }
        else if (location.occupied())
        {
            validMove = false;
        }
        // check movement of two
        if (fromY + specialDirection == toY)
        {
            if (hasMoved())
            {
                validMove = false;
            }
        }
        // check for abnormal movement
        else if (fromY + direction != toY)
        {
            validMove = false;
        }
    }
    else
    {
        validMove = _delegate->canMoveTo(location);
    }

    return validMove;
}

int Pawn::value() const
{
    return 1;
}

void Pawn::setLocation(Square *square)
{
    if (!_delegate && square)
    {
        if (square->getY() == 0 || square->getY() == 7)
        _delegate = new Queen(color());
    }
    if (_delegate)
    {
        _delegate->setLocation(square);
    }
    else
    {
        Piece::setLocation(square);
    }
}

void Pawn::display(std::ostream &outStream) const
{
    if (_delegate)
    {
        _delegate->display(outStream);
    }
    else
    {
        outStream << color() + "P";
    }
}
