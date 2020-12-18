#include "Game.h"

Player &Game::getNextPlayer()
{
    Player *playerToReturn = _nextPlayer;

    _nextPlayer = _players.find(_nextPlayer)->second;

    return *playerToReturn;
}

void Game::initialize()
{

    // Initializes the players, originally I was using references which is bad...
    std::string *playerOneName = new std::string("White");
    std::string *playerTwoName = new std::string("Black");

    Player *playerOne = new Player(*playerOneName);
    Player *playerTwo = new Player(*playerTwoName);

    _players.insert(std::pair<Player *, Player *>(playerOne, playerTwo));
    _players.insert(std::pair<Player *, Player *>(playerTwo, playerOne));


    _nextPlayer = playerOne;

    // Initializes the board
    Board &board = Board::getBoard();

    // Initializes the pieces
    std::string white = "W";
    std::string black = "B";

    // Adds the pawns to each side
    Pawn *bPawn1 = new Pawn(black);
    Pawn *bPawn2 = new Pawn(black);
    Pawn *bPawn3 = new Pawn(black);
    Pawn *bPawn4 = new Pawn(black);
    Pawn *bPawn5 = new Pawn(black);
    Pawn *bPawn6 = new Pawn(black);
    Pawn *bPawn7 = new Pawn(black);
    Pawn *bPawn8 = new Pawn(black);

    Pawn *wPawn1 = new Pawn(white);
    Pawn *wPawn2 = new Pawn(white);
    Pawn *wPawn3 = new Pawn(white);
    Pawn *wPawn4 = new Pawn(white);
    Pawn *wPawn5 = new Pawn(white);
    Pawn *wPawn6 = new Pawn(white);
    Pawn *wPawn7 = new Pawn(white);
    Pawn *wPawn8 = new Pawn(white);

    board.squareAt(0, 6).setOccupier(bPawn1);
    board.squareAt(1, 6).setOccupier(bPawn2);
    board.squareAt(2, 6).setOccupier(bPawn3);
    board.squareAt(3, 6).setOccupier(bPawn4);
    board.squareAt(4, 6).setOccupier(bPawn5);
    board.squareAt(5, 6).setOccupier(bPawn6);
    board.squareAt(6, 6).setOccupier(bPawn7);
    board.squareAt(7, 6).setOccupier(bPawn8);

    board.squareAt(0, 1).setOccupier(wPawn1);
    board.squareAt(1, 1).setOccupier(wPawn2);
    board.squareAt(2, 1).setOccupier(wPawn3);
    board.squareAt(3, 1).setOccupier(wPawn4);
    board.squareAt(4, 1).setOccupier(wPawn5);
    board.squareAt(5, 1).setOccupier(wPawn6);
    board.squareAt(6, 1).setOccupier(wPawn7);
    board.squareAt(7, 1).setOccupier(wPawn8);

    bPawn1->setLocation(&board.squareAt(0, 6));
    bPawn2->setLocation(&board.squareAt(1, 6));
    bPawn3->setLocation(&board.squareAt(2, 6));
    bPawn4->setLocation(&board.squareAt(3, 6));
    bPawn5->setLocation(&board.squareAt(4, 6));
    bPawn6->setLocation(&board.squareAt(5, 6));
    bPawn7->setLocation(&board.squareAt(6, 6));
    bPawn8->setLocation(&board.squareAt(7, 6));

    wPawn1->setLocation(&board.squareAt(0, 1));
    wPawn2->setLocation(&board.squareAt(1, 1));
    wPawn3->setLocation(&board.squareAt(2, 1));
    wPawn4->setLocation(&board.squareAt(3, 1));
    wPawn5->setLocation(&board.squareAt(4, 1));
    wPawn6->setLocation(&board.squareAt(5, 1));
    wPawn7->setLocation(&board.squareAt(6, 1));
    wPawn8->setLocation(&board.squareAt(7, 1));

    _blackPieces = std::set<Piece *>();
    _whitePieces = std::set<Piece *>();

    _blackPieces.insert(bPawn1);
    _blackPieces.insert(bPawn2);
    _blackPieces.insert(bPawn3);
    _blackPieces.insert(bPawn4);
    _blackPieces.insert(bPawn5);
    _blackPieces.insert(bPawn6);
    _blackPieces.insert(bPawn7);
    _blackPieces.insert(bPawn8);

    _whitePieces.insert(wPawn1);
    _whitePieces.insert(wPawn2);
    _whitePieces.insert(wPawn3);
    _whitePieces.insert(wPawn4);
    _whitePieces.insert(wPawn5);
    _whitePieces.insert(wPawn6);
    _whitePieces.insert(wPawn7);
    _whitePieces.insert(wPawn8);

    // Adds rooks
    Rook *bRookL = new Rook(black);
    Rook *bRookR = new Rook(black);
    Rook *wRookL = new Rook(white);
    Rook *wRookR = new Rook(white);

    board.squareAt(0, 7).setOccupier(bRookL);
    board.squareAt(7, 7).setOccupier(bRookR);
    board.squareAt(0, 0).setOccupier(wRookL);
    board.squareAt(7, 0).setOccupier(wRookR);

    bRookL->setLocation(&board.squareAt(0, 7));
    bRookR->setLocation(&board.squareAt(7, 7));
    wRookL->setLocation(&board.squareAt(0, 0));
    wRookR->setLocation(&board.squareAt(7, 0));

    _blackPieces.insert(bRookL);
    _blackPieces.insert(bRookR);
    _whitePieces.insert(wRookL);
    _whitePieces.insert(wRookR);

    // Adds knights
    Knight *bKnightL = new Knight(black);
    Knight *bKnightR = new Knight(black);
    Knight *wKnightL = new Knight(white);
    Knight *wKnightR = new Knight(white);

    board.squareAt(1, 7).setOccupier(bKnightL);
    board.squareAt(6, 7).setOccupier(bKnightR);
    board.squareAt(1, 0).setOccupier(wKnightL);
    board.squareAt(6, 0).setOccupier(wKnightR);

    bKnightL->setLocation(&board.squareAt(1, 7));
    bKnightR->setLocation(&board.squareAt(6, 7));
    wKnightL->setLocation(&board.squareAt(1, 0));
    wKnightR->setLocation(&board.squareAt(6, 0));

    _blackPieces.insert(bKnightL);
    _blackPieces.insert(bKnightR);
    _whitePieces.insert(wKnightL);
    _whitePieces.insert(wKnightR);

    // Adds bishops
    Bishop *bBishopL = new Bishop(black);
    Bishop *bBishopR = new Bishop(black);
    Bishop *wBishopL = new Bishop(white);
    Bishop *wBishopR = new Bishop(white);

    board.squareAt(2, 7).setOccupier(bBishopL);
    board.squareAt(5, 7).setOccupier(bBishopR);
    board.squareAt(2, 0).setOccupier(wBishopL);
    board.squareAt(5, 0).setOccupier(wBishopR);

    bBishopL->setLocation(&board.squareAt(2, 7));
    bBishopR->setLocation(&board.squareAt(5, 7));
    wBishopL->setLocation(&board.squareAt(2, 0));
    wBishopR->setLocation(&board.squareAt(5, 0));

    _blackPieces.insert(bBishopL);
    _blackPieces.insert(bBishopR);
    _whitePieces.insert(wBishopL);
    _whitePieces.insert(wBishopR);

    // Adds queens
    Queen *bQueen = new Queen(black);
    Queen *wQueen = new Queen(white);

    board.squareAt(3, 7).setOccupier(bQueen);
    board.squareAt(3, 0).setOccupier(wQueen);

    bQueen->setLocation(&board.squareAt(3, 7));
    wQueen->setLocation(&board.squareAt(3, 0));

    _blackPieces.insert(bQueen);
    _whitePieces.insert(wQueen);

    // Adds kings
    King *bKing = new King(black);
    King *wKing = new King(white);

    board.squareAt(4, 7).setOccupier(bKing);
    board.squareAt(4, 0).setOccupier(wKing);

    bKing->setLocation(&board.squareAt(4, 7));
    wKing->setLocation(&board.squareAt(4, 0));

    playerTwo->setKing(*bKing);
    playerOne->setKing(*wKing);

    _blackPieces.insert(bKing);
    _whitePieces.insert(wKing);

    playerOne->setPieces(_whitePieces);
    playerTwo->setPieces(_blackPieces);
}

Player &Game::opponentOf(Player &player)
{
    return *_players.find(&player)->second;
}

// initialize static variables
Player *Game::_nextPlayer;
std::map<Player *, Player *> Game::_players;
std::set<Piece *> Game::_whitePieces;
std::set<Piece *> Game::_blackPieces;
