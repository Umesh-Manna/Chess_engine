// Move generation: pseudo legal moves

#include <iostream>
#include <vector>
#include <cctype>

#include "board.hpp"

enum class Pieces {

};

//structure to store a board coordinate
struct Square {
    int row;
    int col; //rank
};

// ## May not really need it after all

// struct Move {
//     int fromRow, fromCol;       //current position of the pieces
//     int toRow, toCol;           //position that the piece should/will go

//     //checking if the special moves are possible
//     //redundant for now, may be usefull later
//     bool isEnPassant = false;
//     bool isCastling = false;
//     int promotionPiece = 0;         //0 if none, enum value of Q, R, B, N
// };

class Move_generator {

public:
    std::vector<std::vector<int>> getKnightMoves(Square current_pos) {
        std::vector<std::vector<int>> valid_moves;

        //Relative offsets for the 8 possible L shapes
        const int drow[] = { 2, 1, -1, -2, -2, -1,  1,  2 };
        const int dcol[] = { 1, 2,  2,  1, -1, -2, -2, -1 };

        //looping through all the possible squars the knight can move based on it's current possition
        //
        for (int i = 0; i < 8; i++) {
            int next_r = current_pos.row + drow[i];
            int next_c = current_pos.col + dcol[i];

            //checking for out of bound, and if the space is empty
            if ((next_r >= 0 && next_r < 8) && (next_c >= 0 && next_c < 8) /*&& (global::board[current_pos.row][current_pos.col] == '.')*/) {        //valid possition
                char target_piece = global::board[next_r][next_c];

                //std::cout << "is this reaching over here" << std::endl;
                //std::cout << target_piece << std::endl;

                for (int i = 0; i < 8; i++) {
                    std::cout << 8 - i << " ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << global::board[i][j] << " "; 
                    }
                    std::cout << std::endl;
                }
                std::cout << "  a b c d e f g h" << std::endl;

                if (target_piece == '.') {
                    valid_moves.push_back({next_r, next_c});
                }
                else {
                    //there is a piece here, check if there is enemy or not
                    //if white's turn, then pieces would be upper case
                    //if black's turn, then pieces would be lower case

                    bool isEnemy = ((global::whiteToMove && isupper(target_piece)) || (!global::whiteToMove && islower(target_piece)));
                        
                    if (isEnemy) {
                        valid_moves.push_back({next_r, next_c});
                    }
                    //else do nothing
                }
                
                
            }
        }

        return valid_moves;
    }


    
};

int main() {
    std::vector<std::vector<int>> valid_moves;

    Move_generator kn; 
    Square currentPos;
    currentPos.row = 3;
    currentPos.col = 0;
    valid_moves = kn.getKnightMoves(currentPos);

    for (auto& r : valid_moves) {
        for (auto& c : r) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

}








