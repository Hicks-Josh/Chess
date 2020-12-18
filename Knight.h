#ifndef CHESS_GAME_FINALE_KNIGHT_H
#define CHESS_GAME_FINALE_KNIGHT_H

#include "Piece.h"

class Square;

class Knight : public Piece
{

public:

    /**
     A constructor for the knight.
     */
    Knight(std::string color);

    /**
     A destructor for the knight.
     */
    ~Knight();

    /**
     Returns a boolean value on whether or not
     the knight can move to a given square.

     @param location a Square reference of the
     location where the knight could potentially move.
     @return a boolean value on whether or not
     the knight can move to the given square.
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the knight.

     @return an int value of the knight.
     */
    int value() const;

    /**
     Displays the knight on the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;
};

#endif
