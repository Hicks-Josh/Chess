#ifndef CHESS_GAME_FINALE_KING_H
#define CHESS_GAME_FINALE_KING_H

#include "RestrictedPiece.h"

class Square;

class King : public RestrictedPiece
{

public:
    /**
     The constructor for king.

     @param color the color of the piece.
     */
    King(std::string color);

    /**
     The destructor for king.
     */
    ~King();

    /**
     Returns a boolean value on whether or not
     the king can move to a given square.

     @param location a Square reference of the
     location where the king could potentially move.
     @return a boolean value on whether or not
     the king can move to the given square.
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the king.

     @return an int value of the king.
     */
    int value() const;

    /**
    Displays the king on the board.

    @param outStream to override the << operator.
    */
    void display(std::ostream &outStream) const;
};

#endif