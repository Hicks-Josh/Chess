#ifndef CHESS_GAME_FINALE_PAWN_H
#define CHESS_GAME_FINALE_PAWN_H

#include "RestrictedPiece.h"

class Square;
class Queen;

class Pawn : public RestrictedPiece
{

public:

    /**
     A constructor for the pawn.
     */
    Pawn(std::string color);

    /**
     A destructor for the pawn.
     */
    ~Pawn();

    /**
     Returns a boolean value on whether or not
     the pawn can move to a given square.

     @param location a Square reference of the
     location where the pawn could potentially move.
     @return a boolean value on whether or not
     the pawn can move to the given square.
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the pawn.

     @return an int value of the pawn.
     */
    int value() const;

    /**
     Sets the location of the piece
     as it could be a different piece
     due to delegation.

     @param square the square to move the pawn to.
     */
    void setLocation(Square *square);

    /**
     Displays the pawn on the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;

private:

    /**
     The delegate of the pawn.
     */
    Queen *_delegate;
};

#endif
