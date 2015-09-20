/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include "header.h"

bool check(vector<char> v){
    bool arr[10] = {false};
    for(char i:v){
        if(i=='.') continue;
        if(arr[i-'0']) {return false;}
        arr[i-'0'] = true;
    }
    return true;
}

bool isValidSudoku(vector<vector<char> >& board) {
    int r = board.size();
    if(!r) return true;
    int c = board[0].size();
    if(!c) return true;
    for(int i=0; i<r; i++) 
        if(!check(board[i])) return false;
    for(int i=0; i<c; i++){
        vector<char> v(r, '.');
        for(int j=0; j<r; j++) v[j] = board[j][i];
        if(!check(v)) return false;
    }
    int x = sqrt(r);
    for(int i=0; i<r; i+=x){
        for(int j=0; j<r; j+=x){
            vector<char> v(r, '.');
            for(int m=0; m<x; m++)
                for(int n=0; n<x; n++)
                    v[m*x+n] = board[m+i][n+j];
            if(!check(v)) return false;
        }
    }
    return true;
}

int main(){
    string b[] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    vector<vector<char> > board(sizeof(b)/sizeof(b[0]),vector<char>(sizeof(b[0])/sizeof(b[0][0], '.')));
    for(int i=0; i<sizeof(b)/sizeof(b[0]); i++){
        for(int j=0; j<b[i].size(); j++)
            board[i][j] = b[i][j];
    }
    bool res = isValidSudoku(board);
    printf("%s\n", res?"true":"false");
    return 0;
}
