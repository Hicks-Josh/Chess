#include "Player.h"
#include "Board.h"
#include "Game.h"

Player::Player(std::string &name) : _name(&name)
{
}

Player::~Player()
{
}

void Player::setPieces(std::set<Piece *> &pieces)
{
    _myPieces = &pieces;
}

void Player::setKing(King &king)
{
    _myKing = &king;
}

bool Player::makeMove()
{
    std::string start;
    std::string goal;
    Board& board = Board::getBoard();
    bool validInput;

    do
    {
        std::cout << getName() << " enter move: ";
        std::cin >> start >> goal;

        Square *startSquare = &board.squareAt(start);
        Square *goalSquare = &board.squareAt(goal);

        // if startSquare isn't occupied, then
        if (!startSquare->occupied())
        {
            validInput = false;
        }
        else
        {
            Piece *pieceToMove = &startSquare->occupiedBy();

            validInput = pieceToMove->moveTo(*this, *goalSquare);
        }
    } while (!validInput);

    // checks for putting opponent in check
    if (Game::opponentOf(*this).checkForCheck())
    {
        std::cout << "check\n" << std::endl;
    }

    return true;
}

std::string &Player::getName() const
{
    return *_name;
}

int Player::score() const
{
    return _score;
}

void Player::capture(Piece &aPiece)
{
    _captured.insert(&aPiece);
    Game::opponentOf(*this).myPieces().erase(&aPiece);
    _score += aPiece.value();
}

std::set<Piece *> &Player::myPieces() const
{
    return *_myPieces;
}

King &Player::myKing() const
{
    return *_myKing;
}

bool Player::checkForCheck()
{
    Square* myKingLocation = &myKing().location();
    Player* myOpponent = &Game::opponentOf(*this);
    bool isInCheck = false;

    for (Piece* piece : myOpponent->myPieces())
    {
        if (piece->isOnBoard())
        {
            if (piece->canMoveTo(*myKingLocation))
            {
                isInCheck = true;
            }
        }
    }

    return isInCheck;
}