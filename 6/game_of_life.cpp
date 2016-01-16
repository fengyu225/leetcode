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

int directions[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};

void gameOfLife(vector<vector<int> >& board) {
    if(board.size() == 0 || board[0].size() == 0) return;
    int m = board.size(), n = board[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int live_cnt = 0;
            for(int d=0; d<8; d++){
                int new_x = directions[d][0]+i;
                int new_y = directions[d][1]+j;
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && board[new_x][new_y]&1)
                    live_cnt++;
            }
            if(board[i][j]&1){
                if(live_cnt == 2 || live_cnt == 3) board[i][j]|=2;
            }
            else if(live_cnt == 3) board[i][j]|=2;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) board[i][j]>>=1;
    }
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