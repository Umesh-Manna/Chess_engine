// Move generation: pseudo legal moves

#include <iostream>
#include <vector>

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

class move_generator {

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

            //checking for out of bound
            if ((next_r < 8 && next_c < 8) /*&& (board[current_pos.row][current_pos.col])*/) {        //valid possition
                valid_moves.push_back({next_r, next_c});
            }
        }

        return valid_moves;
    }
};








