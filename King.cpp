#include "King.h"

King::King(std::string color)
        : RestrictedPiece(color)
{
}

King::~King()
{
}

bool King::canMoveTo(Square &location) const
{
    bool isValid = false;

    int xVal = std::abs(Piece::location().getX() - location.getX()),
    yVal = std::abs(Piece::location().getY() - location.getY());

    // check for valid cases
    if (xVal == 0 && yVal == 1
    || xVal == 1 && yVal == 0
    || xVal == 1 && yVal == 1)
    {
        isValid = true;
    }

    return isValid;
}

int King::value() const
{
    return 0;
}

void King::display(std::ostream &outStream) const
{
    outStream << color() + "K";
}
