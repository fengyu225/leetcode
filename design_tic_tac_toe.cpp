/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
*/

#include "header.h"

class TicTacToe {
    vector<vector<int> > board;
    int size;
    bool check_row(int row, int player){
        for(int i=0; i<size; i++){
            if(board[row][i] != player) return false;
        }
        return true;
    }
    bool check_col(int col, int player){
        for(int i=0; i<size; i++){
            if(board[i][col] != player) return false;
        }
        return true;
    }
    bool check_diag_1(int row, int col, int player){
        if(row != col) return false;
        for(int i=0; i<size; i++)
            if(board[i][i] != player) return false;
        return true;
    }
    bool check_diag_2(int row, int col, int player){
        if(row+col != size-1) return false;
        for(int i=0; i<size; i++)
            if(board[i][size-1-i] != player) return false;
        return true;
    }
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0)); 
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
//        for(auto v : board) print_vector<int>(v);
        if(
                check_row(row, player) || 
                check_col(col, player) || 
                check_diag_1(row, col, player) || 
                check_diag_2(row, col, player)
                )
            return player;
        else return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main(){
    TicTacToe obj(3);
//    cout<<obj.move(0, 0, 1)<<endl;
//    cout<<obj.move(0, 2, 2)<<endl;
//    cout<<obj.move(2, 2, 1)<<endl;
//    cout<<obj.move(1, 1, 2)<<endl;
//    cout<<obj.move(2, 0, 1)<<endl;
//    cout<<obj.move(1, 0, 2)<<endl;
//    cout<<obj.move(2, 1, 1)<<endl;


    cout<<obj.move(1, 2, 2)<<endl;
    cout<<obj.move(0, 2, 1)<<endl;
    cout<<obj.move(0, 0, 2)<<endl;
    cout<<obj.move(2, 0, 1)<<endl;
    cout<<obj.move(0, 1, 2)<<endl;
    cout<<obj.move(1, 1, 1)<<endl;
    return 0;
}
