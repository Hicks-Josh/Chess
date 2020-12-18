#ifndef CHESS_GAME_FINALE_RESTRICTEDPIECE_H
#define CHESS_GAME_FINALE_RESTRICTEDPIECE_H

#include "Piece.h"

class Player;
class Square;

class RestrictedPiece : public Piece
{
public:

    /**
     The constructor for the restricted piece.

     @param color the color of the piece.
     */
    RestrictedPiece(std::string color);

    /**
     A destructor for RestrictedPiece.
     */
    virtual ~RestrictedPiece();

    /**
     Moves the piece to a specified location.

     @param byPlayer the player who moved the piece.
     @param to the square to which the piece
     should move.
     */
    virtual bool moveTo(Player &byPlayer, Square &to);

protected:

    /**
     Checks to see if the piece has moved.

     @return a boolean value based on whether or not
     the piece has moved.
     */
    bool hasMoved() const;

private:

    /**
     A boolean value based on whether or not
     the piece has moved.
     */
    bool _moved = false;
};

#endif
