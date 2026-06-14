

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>

class Move {
    int from_square;
    int to_square;
};

class ChessBoard {
public:
    char board[8][8];
    bool whiteToMove;

    //as soon as the class is called, a empty board will be created
public:
    ChessBoard() {
        resetBoard();
    }

//resetting the value to empty by default
public:
    void resetBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = '.';
            }
        }
    }
    

public:
    void loadFromFEN(const std::string& fen) {
        
        //first part of the fen
        int idx = 0; //pointer that keeps track of 'fen' string
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //if '/'
                if (fen[idx] == '/') {
                    idx++;
                }

                //if number or char
                if (isdigit(fen[idx])) {
                    j += fen[idx];
                    idx++;
                }
                else {
                    board[i][j] = fen[idx];
                    idx++;
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            std::cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "  a b c d e f g h" << std::endl;
        
    }

public:
    void printBoard() {
        for (int i = 0; i < 8; i++) {
            std::cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                std::cout << board[i][j] << " "; 
            }
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
    board.loadFromFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    //board.printBoard();
    return 0 ;
}
