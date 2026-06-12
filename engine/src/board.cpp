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
    Color w = Color::white; 
    Color b = Color::black;
    Castle kS = Castle::king_side;
    Castle qS = Castle::queen_side;

    std::string en_passant;
    //chess board for visual representation on the terminal
    std::array <char, NB_SQ> board;
    std::array <std::array<bool, NB_CASTLE>, NB_COLOR> castle_rights;


public: 
    ChessBoard() {
//setting every board to empty by default 
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
        const size_t size = fen.size();
        size_t iter = 0; 
        int index = 0; 

        //parses the first pieces part of the FEN string
        for ( ; (iter < size) && (fen[iter] != ' '); iter++) {
            if (fen[iter] == '/') {
                continue;
            }
            
            //check if the char is number, convert it to char type
            if (isdigit(fen[iter])) {
                index += (fen[iter] - '0');
            }
            else {
                board[index] = fen[index];
                ++index;
            }
        }

        

        turn = fen[iter +1] == 'w' ? w : b;

        for (iter += 3; (iter < size) and (fen[iter] != ' '); iter++){
            if (fen[iter] == 'k')
                castle_rights[static_cast<bool>(b)][static_cast<bool>(kS)] = true;
            else if (fen[iter] == 'K')
                castle_rights[static_cast<bool>(w)][static_cast<bool>(kS)] = true;
            else if (fen[iter] == 'q') 
                castle_rights[static_cast<bool>(b)][static_cast<bool>(qS)] = true;
            else if (fen[iter] == 'Q') {
                castle_rights[static_cast<bool>(w)][static_cast<bool>(qS)] = true;
            }
        }

        en_passant = fen.substr(iter + 1, 3);
    }

public:
    void printBoard() {
        for (int i = 0; i < NB_SQ; i++)
        {
            if (i % 8 == 0) std::cout << '\n';
            std::cout << board[i] << ' ';
        }

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
