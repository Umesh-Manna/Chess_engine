//initialization and board operations

//initializing the starting position

#include <iostream>
#include "Board.h"
#include "Piece.h"

Class Board() {
public:
    Board() {}
    void initializeBoard() {
        //initializes board

    }

    void printBoard() {
        //prints board
        for  (size_t i = 0; i < 8; i++) {
            for (size_t j = 0; j < 8; j++) {
                std::cout << board[i][j];
            }
        }
    }

};