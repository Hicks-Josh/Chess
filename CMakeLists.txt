cmake_minimum_required(VERSION 3.16)
project(Chess_Game_Finale)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess_Game_Finale Game.cpp Game.h Bishop.cpp Bishop.h Queen.cpp Queen.h King.cpp King.h Pawn.cpp Pawn.h Rook.cpp Rook.h RestrictedPiece.cpp RestrictedPiece.h Chess.cpp Board.cpp Board.h Square.cpp Square.h Player.cpp Player.h Piece.cpp Piece.h Knight.cpp Knight.h)