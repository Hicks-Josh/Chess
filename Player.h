#ifndef CHESS_GAME_FINALE_PLAYER_H
#define CHESS_GAME_FINALE_PLAYER_H

#include <iostream>
#include <string>
#include <set>

class Piece;
class King;

class Player
{
public:

    /**
     A constructor for Player.

     @param name a string of the name for the player.
     */
    Player(std::string &name);

    /**
     A destructor for player.
     */
    ~Player();

    /**
     Sets the pieces for the player.

     @param pieces a set of pieces the player has.
     */
    void setPieces(std::set<Piece *> &pieces);

    /**
     Sets the king for player.

     @param king a reference of the player's king.
     */
    void setKing(King &king);

    /**
     Let's the player make it's turn.

     @return a boolean value of whether
     or not the player has moved.
     */
    bool makeMove();

    /**
     Returns the name of the player.

     @return a string of the player's name.
     */
    std::string &getName() const;

    /**
     The player's score.

     @return an int of the player's score.
     */
    int score() const;

    /**
     Captures the given piece.

     @param aPiece the piece to capture.
     */
    void capture(Piece &aPiece);

    /**
     A set of the player's pieces.

     @return a set of the player's pieces.
     */
    std::set<Piece *> &myPieces() const;

    /**
     The player's king.

     @return a reference to the player's king.
     */
    King &myKing() const;

    bool checkForCheck();

private:


    /**
     The name of the player.
     */
    std::string *_name;

    /**
     The set of pieces the player owns.
     */
    std::set<Piece *> *_myPieces;

    /**
     The set of captured pieces.
     */
    std::set<Piece *> _captured;

    /**
     The player's king.
     */
    King *_myKing;

    /**
     * The score
     */
    int _score = 0;
};

#endif
