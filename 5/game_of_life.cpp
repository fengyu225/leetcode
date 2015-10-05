/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

#include "header.h"

void update(vector<vector<int> >& board, int i, int j, int r, int c){
    int move[8][2] = {
        {0, 1},
        {0, -1},
        {1, 1},
        {1, -1},
        {1, 0},
        {-1, 1},
        {-1, -1},
        {-1, 0}
    }; 
    int live_count = 0;
    for(int x=0; x<8; x++){
        int new_x = move[x][0]+i;
        int new_y = move[x][1]+j;
        if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && board[new_x][new_y]&1)
            live_count++;
    }
    if(board[i][j]&1){
        if(live_count == 2 || live_count == 3) board[i][j]|=2;
    }
    else{
        if(live_count == 3) board[i][j] |= 2;
    }
}

void gameOfLife(vector<vector<int> >& board) {
    int r = board.size();
    if(r == 0) return;
    int c = board[0].size();
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) update(board, i, j, r, c);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) board[i][j]>>=1;
}

int main(){
    vector<vector<int> > board = {
        {0, 1, 0}, 
        {0, 0, 0}, 
        {1, 0, 1} 
    };
    gameOfLife(board);
    print_2d_vector<int>(board);
    return 0;
}