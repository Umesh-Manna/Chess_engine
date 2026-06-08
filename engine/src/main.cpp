//chess engine day one
//no point in thinking too much, let's just begin
#include <iostream>
#include <string>
#include <vector>

class Move {
    int from_square;
    int to_squuare; 
};


class ChessBoard {
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

