
## Problem

How should the chessboard be represented internally? 

## Options Considered

```cpp
1. vector<vector<Piece>>;
2. std::array<std::array<Piece, 8>, 8>;
3. // 1D array of 64 squares
4. //Bitboard(uint64_t)
```

## Decision

```cpp
std::array<std::array<Piece, 8>, 8>;
```

## Reasoning

1. Fixed board dimensions
2. Simple indexing
3. Easy visualization and debugging
4. Sufficient of initial engine

## Trade offs

1. Less optimized than bit-boards
2. May require redesign if the performance is a bottleneck


## Revisit when? 

When the board representation starts becoming the bottleneck of the performance
