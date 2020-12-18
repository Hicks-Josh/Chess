#ifndef CHESS_GAME_FINALE_SQUARE_H
#define CHESS_GAME_FINALE_SQUARE_H

class Piece;

class Square
{

public:

    /**
     A constructor for the square.

     @param x the x coordinate for the square.
     @param y the y coordinate for the square.
     */
    Square(int x, int y);

    /**
     A destructor for square.
     */
    ~Square();

    /**
     Returns the x coordinate.

     @return the x coordinate.
     */
    int getX() const;

    /**
     Returns the y coordinate.

     @return the y coordinate.
     */
    int getY() const;

    /**
     Checks if the square is occupied by a piece.

     @return a boolean value based on whether
     or not the square is occupied.
     */
    bool occupied() const;

    /**
     Checks what piece the square is occupied by.

     @return a refernce to the piece occupying
     the square.
     */
    Piece &occupiedBy() const;

    /**
     Sets the piece to occupy the square.

     @param piece the piece to occupy the square.
     */
    void setOccupier(Piece *piece);

private:

    /**
     The x coordinate of the square.
     */
    int _x;

    /**
     The y coordinate of the square.
     */
    int _y;

    /**
     The piece occupying the square.
     */
    Piece *_piece;
};

#endif