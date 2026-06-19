#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
#include <algorithm>

#include "board.hpp"

enum class Color {
    white = 0,
    black = 1
};

enum class Castle {
    king_side = 0,
    queen_side = 1
};

class Move {
    int from_square;
    int to_square;
};


class ChessBoard {
public:           //first part of the FEN string showing the position of the pieces
    bool whiteToMove;               //keeps track of the turn to play
    bool castle_rights[2][2];       //keeps track of the castelling rights
    std::string epTracker;           //temporary variable created for tracking en passant


    //as soon as the class is called, a empty board will be created
public:
    ChessBoard() 
    : castle_rights{}         //setting all value of castle-rights to false at start
    {
        resetBoard();
    }

//resetting the value to empty by default
public:
    void resetBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                global::board[i][j] = '.';
            }
        }
    }
    

public:
    void loadFromFEN(const std::string& fen) {
        
        //--------//
        //1st part of the fen
        //For simply printing the pieces in the board
        //--------//

        int idx = 0; //pointer that keeps track of 'fen' string
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //if '/'
                if (fen[idx] == '/') {
                    idx++;
                }

                //if the current value of FEN string is a number or a char(piece)      
                if (isdigit(fen[idx])) {
                    j += (fen[idx] - '0') -1;
                    idx++;
                }
                else {
                    global::board[i][j] = fen[idx];
                    idx++;
                }
            }
        }        

        //--------//
        //2nd part of the FEN string
        //To keep track of: Which piece to move
        //--------//

        idx++; 
        whiteToMove = fen[idx] == 'w' ? true : false;
        idx += 2;

        //--------//
        //3rd part of FEN string
        //To keep track of: castling rights
        //--------//


        while (fen[idx] != ' ') {
            if (fen[idx] == 'K') {
                castle_rights[static_cast<int>(Color::white)][static_cast<int>(Castle::king_side)] = true;

            }
            else if (fen[idx] == 'k') {
                castle_rights[static_cast<int>(Color::black)][static_cast<int>(Castle::king_side)] = true;
            }
            else if (fen[idx] == 'Q') {
                castle_rights[static_cast<int>(Color::white)][static_cast<int>(Castle::queen_side)] = true;
            }
            else if(fen[idx] == 'q') {
                castle_rights[static_cast<int>(Color::black)][static_cast<int>(Castle::queen_side)] = true;
            }
            else {   
                break;
            }

            idx++;
        }

    }

public:
    void printBoard() {
        for (int i = 0; i < 8; i++) {
            std::cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                std::cout << global::board[i][j] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << "  a b c d e f g h" << std::endl;
    }

public: 
    // std::vector<Move> generatePseudoLegalMoves() {
    //     std::vector<Move> moves; 
    //     //todo: loop through the sqares, find pieces and calculate where they go....
    //     return moves;        
    // }

};

int main() {
    ChessBoard board;
    //this is the starting position of the board..
    //board.loadFromFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"); 

    board.loadFromFEN("8/8/8/8/3N4/8/8/8 b - - 0 1"); 
    board.printBoard();
    return 0 ;
}
