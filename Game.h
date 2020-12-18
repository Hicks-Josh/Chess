#ifndef CHESS_GAME_FINALE_GAME_H
#define CHESS_GAME_FINALE_GAME_H

#include <set>
#include <map>

#include "Player.h"
#include "Board.h"
#include "Square.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class Game
{

public:

    /**
     Retrieves the next player to move.

     @return Player& the next player to move.
     */
    static Player &getNextPlayer();

    /**
     Initializes the board, squares and pieces.
     */
    static void initialize();

    /**
     The two competing players.

     @param player the current player.
     @return a player reference of the competing player.
     */
    static Player &opponentOf(Player &player);

private:

    /**
     The other competing player.
     */
    static Player *_nextPlayer;

    /**
     The competing players.
     */
    static std::map<Player *, Player *> _players;

    /**
     A set of white pieces.
     */
    static std::set<Piece *> _whitePieces;

    /**
     A set of black pieces.
     */
    static std::set<Piece *> _blackPieces;
};

#endif