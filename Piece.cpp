#include "Piece.h"

Piece::Piece(std::string& color) : _color(color), _square(nullptr)
{
}

Piece::~Piece()
{
}

bool Piece::moveTo(Player& byPlayer, Square& to)
{
    Piece* potentialOccupant = nullptr;
    Square* originalSquare = &location();
    bool validMove = true;

    // check for the correct color
    if (byPlayer.getName().find(color()) == std::string::npos)
    {
        validMove = false;
    }
    else if (canMoveTo(to))
    {
        // checks to see if there is a piece to capture
        if (to.occupied())
        {
            potentialOccupant = &to.occupiedBy();
            // checks for valid color
            if (byPlayer.getName().find(potentialOccupant->color()) !=
                std::string::npos)
            {
                validMove = false;
            }
            // if there is a valid piece to capture, capture it
            else
            {
                potentialOccupant->setLocation(nullptr);
            }
        }

        if (validMove)
        {
            // move the piece
            location().setOccupier(nullptr);
            setLocation(&to);
            to.setOccupier(this);

            // check for check, undo moves if necessary
            if (byPlayer.checkForCheck())
            {
                // if there was a capture, reverse
                if (potentialOccupant)
                {
                    potentialOccupant->setLocation(&to);
                }
                setLocation(originalSquare);
                location().setOccupier(this);
                to.setOccupier(potentialOccupant);

                validMove = false;
            }
            else
            {
                /*
                 * if it's a valid move and there is a piece to capture,
                 * capture
                 */
                if (potentialOccupant)
                {
                    byPlayer.capture(*potentialOccupant);
                }
            }
        }
    }
    else
    {
        validMove = false;
    }

    return validMove;
}

std::string Piece::color() const
{
    return _color;
}

void Piece::setLocation(Square *square)
{
    _square = square;
}

bool Piece::isOnBoard() const
{
    return _square;
}

Square &Piece::location() const
{
    return *_square;
}
