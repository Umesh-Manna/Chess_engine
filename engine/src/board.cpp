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
private:
    Color turn;
    std::string en_passant;
    //chess board for visual representation on the terminal
    std::array <char, NB_SQ> board;
    std::array <std::array<bool, NB_CASTLE>, NB_COLOR> castle_rights;


public: 
    ChessBoard() {
        for (int i = 0; i < NB_SQ; i++) board[i] = '.';
        
        //setting everything up as default in general
        for (int i = 0; i < NB_COLOR; i++) {
            for (int j = 0; j < NB_CASTLE; j++) {
                castle_rights[i][j] = false;
            }
        }
    }




public:
    void loadFromFEN(const std::string& fen) {
        //todo : parse the fen string
    }

public:
    void printBoard() {
        //todo : Print 8*8 board using terminal using letters

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
