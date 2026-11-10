//Board definitions

#ifndef BOARD_H
#define BOARD_H

#pragma once
#include <array>

#include "Piece.h"

class Board
{
private:
    std::array<std::array<int, 8>, 8> board;
    
public:
    //constructor
    Board();
    
    //initializing starting chess position
    void initialize();

    //get piece at a perticular square
    Piece getPiece(int row, int col);

    //place a piece at a perticular square
    void setPiece(int row, int col, Piece piece);

    //move a piece from one square to another
    void movePiece(int startRow, int startCol, int endRow, int endCol);

    //display board at the terminal
    void print() const;
};

#endif