#ifndef CHESS_GAME_FINALE_ROOK_H
#define CHESS_GAME_FINALE_ROOK_H

#include "RestrictedPiece.h"
#include "Board.h"

class Square;

class Rook : public RestrictedPiece
{

public:
    /**
     A constructor for the rook.

     @param color the color of the rook.
     */
    Rook(std::string color);

    /**
     A destructor for the rook.
     */
    ~Rook();

    /**
     Returns a boolean value on whether or not
     the rook can move to a given square.

     @param location a Square reference of the
     location where the rook could potentially move.
     @return a boolean value on whether or not
     the rook can move to the given square.
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the rook.

     @return an int value of the rook.
     */
    int value() const;

    /**
     Displays the rook on the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;
};
#endif
