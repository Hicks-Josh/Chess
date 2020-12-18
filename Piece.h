#ifndef CHESS_GAME_FINALE_PIECE_H
#define CHESS_GAME_FINALE_PIECE_H

#include <ostream>
#include <string>

#include "Square.h"
#include "Player.h"

class Player;

class Piece
{

public:

    /**
     A constructor for piece.

     @param color a string determining
     the color.
     */
    Piece(std::string& color);

    /**
     A destructor for the piece.
     */
    virtual ~Piece();

    /**
     Moves the piece to a specified location.

     @param byPlayer the player who moved the piece.
     @param to the square to which the piece
     should move.
     */
    virtual bool moveTo(Player &byPlayer, Square &to);

    /**
     A pure virtual value method.

     @return the int value of the piece.
     */
    virtual int value() const = 0;

    /**
     The color of the piece.

     @return the color of the piece.
     */
    std::string color() const;

    /**
     A pure virtual display method.

     @param outStream to override the << operator.
     */
    virtual void display(std::ostream &outStream) const = 0;

    /**
     A pure virtual canMoveTo method which determines
     if a piece can move to the given square.

     @param location the square where the piece could move to.
     @return a boolean value based on whether or not
     the piece can move to the specified location.
     */
    virtual bool canMoveTo(Square &location) const = 0;

    /**
     Sets the piece's location to the given square.

     @param square the location to move the square.
     */
    virtual void setLocation(Square *square);

    /**
     Checks if the piece is on the board.

     @return a boolean value based on whether
     or not the piece is on the board.
     */
    bool isOnBoard() const;

    /**
     Returns the location of the piece.

     @return the reference to the square
     the piece is on.
     */
    Square &location() const;

private:

    /**
     The color of the piece.
     */
    std::string _color;

    /**
     The square the piece currently resides on.
     */
    Square *_square;
};

#endif
