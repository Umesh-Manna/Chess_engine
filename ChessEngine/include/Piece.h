//piece definitions

#ifndef PIECE_H
#define PIECE_H

enum class PieceType {
    NONE, 
    PAWN, 
    KNIGHT, 
    BISHOP, 
    ROOK, 
    QUEEN, 
    KING
};

enum class Color {
    WHITE, 
    BLACK, 
    NONE
};

struct Piece {
    PieceType type;
    Color color;
};

#endif