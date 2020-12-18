#include "Board.h"
#include <iostream>
#include <vector>

Board &Board::getBoard()
{
    return *_theBoard;
}

Square &Board::squareAt(int x, int y) const
{
    Square *square = nullptr;

    // checks if coordinates are in array bounds
    if (x < _DIMENSION && y < _DIMENSION)
    {
        square = _squares[x][y];
    }

    return *square;
}

Square &Board::squareAt(std::string location) const
{
    return (squareAt(location[0] - 'a', location[1] - '1'));
}

int Board::distanceBetween(Square &from, Square &to) const
{
    int fromX = from.getX(), fromY = from.getY(),
    toX = to.getX(), toY = to.getY(), distanceBetween;

    // if the distance between axis are greater than the y
    if (std::abs(fromX - toX) > std::abs(fromY - toY))
    {
        distanceBetween = std::abs(fromX - toX);
    }
    else
    {
        distanceBetween = std::abs(fromY - toY);
    }

    return distanceBetween;
}

bool Board::isClearVertical(Square &from, Square &to) const
{
    bool isClear = true;
    int fromX = from.getX(), fromY = from.getY(),
    toX = to.getX(), toY = to.getY(), multiplier = 1;

    if (fromX != toX)
    {
        isClear = false;
    }
    else
    {
        // if only moving one square it's clear
        if (std::abs(fromX - toX) != 1)
        {
            // moving down
            if (fromY > toY)
            {
                multiplier = -1;
            }
            toY += -multiplier;
            while(fromY != toY && isClear)
            {
                fromY += multiplier;
                if (squareAt(fromX, fromY).occupied())
                {
                    isClear = false;
                }
            }
        }
    }

    return isClear;
}

bool Board::isClearHorizontal(Square &from, Square &to) const
{
    bool isClear = true;
    int fromX = from.getX(), fromY = from.getY(),
            toX = to.getX(), toY = to.getY(), multiplier = 1;

    if (fromY != toY)
    {
        isClear = false;
    }
    else
    {
        // if only moving one square it's clear
        if (std::abs(fromY - toY) != 1)
        {
            // moving left
            if (fromX > toX)
            {
                multiplier = -1;
            }
            toX += -multiplier;
            while(fromX != toX && isClear)
            {
                fromX += multiplier;
                if (squareAt(fromX, fromY).occupied())
                {
                    isClear = false;
                }
            }
        }
    }

    return isClear;
}

bool Board::isClearDiagonal(Square &from, Square &to) const
{
    bool isClear = true;
    int fromX = from.getX(), fromY = from.getY(),
    toX = to.getX(), toY = to.getY(), xMultiplier = -1, yMultiplier = -1;

    // check for correct diagonal movement
    if (std::abs(fromX - toX) != std::abs(fromY - toY))
    {
        isClear = false;
    }
    else
    {
        // moving right
        if (fromX < toX)
        {
            xMultiplier = 1;
        }
        // moving up
        if (fromY < toY)
        {
            yMultiplier = 1;
        }
        toX += -xMultiplier;
        while (fromX != toX && isClear)
        {
            fromX += xMultiplier;
            fromY += yMultiplier;
            if (squareAt(fromX, fromY).occupied())
            {
                isClear = false;
            }
        }
    }

    return isClear;
}

void Board::display(std::ostream &outStream) const
{
    // top part to start the properly formatted board
    outStream << "     a    b    c    d    e    f    g    h" << std::endl
              << "  -----------------------------------------" << std::endl;

    // outputs the columns
    for (int column = _DIMENSION - 1; column > -1; column--)
    {
        outStream << column + 1 << " | ";

        // outputs rows for each column
        for (int row = 0; row < _DIMENSION; row++)
        {
            // if there is a piece in specified square output it
            if (squareAt(row, column).occupied())
            {
                squareAt(row, column).occupiedBy().display(outStream);
            }
            else
            {
                outStream << "  ";
            }

            outStream << " | ";
        }

        outStream << column + 1 << std::endl;
        outStream << "  -----------------------------------------" << std::endl;
    }

    outStream << "     a    b    c    d    e    f    g    h" << std::endl;
    outStream << std::endl;
}

Board::Board()
{
    for (int column = 0; column < _DIMENSION; column++)
    {
        for (int row = 0; row < _DIMENSION; row++)
        {
            _squares[column][row] = new Square(column, row);
        }
    }
}

Board::~Board()
{
}

Board *Board::_theBoard = new Board();