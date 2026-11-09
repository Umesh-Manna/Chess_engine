#pragma once

#include <vector>

class ChessBoard
{
private:
    std::vector<std::vector<int>> board;

public:
    ChessBoard() 
        : board(8, std::vector<int> (8)) {};
    void resetBoard();
    void loadFromFEN(const std::string& fen);
    



    inline static char board[8][8];
    inline static bool whiteToMove;
};

class ChessBoard {
private: 
    
};  
