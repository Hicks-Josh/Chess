#ifndef CHESS_GAME_FINALE_BISHOP_H
#define CHESS_GAME_FINALE_BISHOP_H

#include "Piece.h"
#include "Board.h"

class Square;

class Bishop : public Piece
{

public:
    /**
     Constructor for the Bishop class.

     @param color the color of which
     the bishop will be apart of.
     */
    Bishop(std::string color);

    /**
     Destructor for the Bishop class.
     */
    ~Bishop();

    /**
     Returns a boolean value on whether or not
     the bishop can move to a given square.

     @param location a Square reference of the
     location where the bishop could potentially move.
     @return a boolean value on whether or not
     the bishop can move to the given square
     */
    bool canMoveTo(Square &location) const;

    /**
     Returns the value of the bishop.

     @return an int value of the bishop.
     */
    int value() const;

    /**
     Displays the bishop on the board.

     @param outStream to override the << operator.
     */
    void display(std::ostream &outStream) const;
};

#endif
