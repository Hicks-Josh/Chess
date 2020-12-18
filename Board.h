#ifndef CHESS_GAME_FINALE_BOARD_H
#define CHESS_GAME_FINALE_BOARD_H

#include <ostream>
#include <string>
#include <map>

#include "Square.h"
#include "Piece.h"

class Square;

class Board
{
public:

    /**
     A getter for the board.

     @return a reference to the board itself.
     */
    static Board &getBoard();

    /**
     Returns a reference to the specified square.

     @param x the x coordinate for the square.
     @param y the y coordinate for the square.
     @return a reference to the specified square.
     */
    Square &squareAt(int x, int y) const;

    /**
     Returns a refernce to the specified square.

     @param location a string defining the
     location of the square.
     @return a reference to specified square.
     */
    Square &squareAt(std::string location) const;

    /**
     Calculates the distance between two specified squares.
     @param from the initial square.
     @param to the destination square.
     @return an int distance between the two specified squares.
     */
    int distanceBetween(Square &from, Square &to) const;

    /**
     Determines if the squares between the two
     specified squares is clear from any pieces.

     @param from the initial square.
     @param to the destination square.
     @return a boolean value whether or not the
     squares between the given squares are clear.
     */
    bool isClearVertical(Square &from, Square &to) const;

    /**
     Determines if the squares between the two
     specified squares is clear from any pieces.

     @param from the initial square.
     @param to the destination square.
     @return a boolean value whether or not the
     squares between the given squares are clear.
     */
    bool isClearHorizontal(Square &from, Square &to) const;

    /**
     Determines if the squares between the two
     specified squares is clear from any pieces.

     @param from the initial square.
     @param to the destination square.
     @return a boolean value whether or not the
     squares between the given squares are clear.
     */
    bool isClearDiagonal(Square &from, Square &to) const;

    /**
     Displays the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;

private:

    /**
     The board constructor.
     */
    Board();

    /**
     The board destructor.
     */
    ~Board();

    /**
     A static board.
     */
    static Board *_theBoard;

    /**
     The dimensions of the board: 8.
     */
    const static int _DIMENSION = 8;

    /**
     The squares in the board.
     */
    Square *_squares[_DIMENSION][_DIMENSION];
};

#endif