#ifndef CHESS_GAME_FINALE_QUEEN_H
#define CHESS_GAME_FINALE_QUEEN_H

#include "Piece.h"
#include "Board.h"

class Square;

class Queen : public Piece
{

public:

    /**
     A constructor for the queen.

     @param color the color of the piece.
     */
    Queen(std::string color);

    /**
     A destructor for the queen.
     */
    ~Queen();

    /**
     Returns a boolean value on whether or not
     the queen can move to a given square.

     @param location a Square reference of the
     location where the queen could potentially move.
     @return a boolean value on whether or not
     the queen can move to the given square.
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the queen.

     @return an int value of the queen.
     */
    int value() const;

    /**
     Displays the queen on the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;
};

#endif
