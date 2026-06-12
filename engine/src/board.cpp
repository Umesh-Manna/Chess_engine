//chess engine day one
//no point in thinking too much, let's just begin
//orginally this was in main.cpp, but i think this file is better suited for board.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>

#define NB_SQ 64  //No. of square
#define NB_CASTLE 2 //No. of castle
#define NB_COLOR 2 // No. of color

enum class Castle {
    king_side, 
    queen_side
};

enum class Color {
    white, black
};


class Move {
    int from_square;
    int to_squuare; 
};

class ChessBoard {
public:
    void loadFromFEN(const std::string& fen) {
        
    }

public:
    void printBoard() {

    }

public: 
    std::vector<Move> generatePseudoLegalMoves() {
        std::vector<Move> moves; 
        //todo: loop through the sqares, find pieces and calculate where they go....
        return moves;        
    }

};

int main() {
    ChessBoard board;
    //this is the starting position of the board..
    board.loadFromFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    board.printBoard();
    return 0 ;
}
