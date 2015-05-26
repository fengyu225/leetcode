/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include "header.h"

bool isValidSudoku(vector<vector<char> > &board) {
    int row = board.size(), col = board[0].size();
    vector<bool> map(10,false);
    for(int i=0; i<row; i++){
        fill(map.begin(), map.end(), false);
        for(int j=0; j<col; j++){
            char c = board[i][j];
            if(c<='9' && c>='0'){
                if(map[(c-'0')-1]) return false;
                map[(c-'0')-1]=true;
            }
        }
    }
    for(int i=0; i<col; i++){
        fill(map.begin(), map.end(), false);
        for(int j=0; j<row; j++){
            char c = board[j][i];
            if(c>='0' && c<='9'){
                if(map[(c-'0')-1]) return false;
                map[(c-'0')-1]=true;
            }
        }
    }
    for(int i=0; i<9; i++){
        int r = i/3*3;
        int c = i%3*3;
        fill(map.begin(), map.end(), false);
        for(int x=r; x<r+3; x++){
            for(int y=c; y<c+3; y++){
                char c = board[x][y];
                if(c>='0' && c<='9'){
                    if(map[(c-'0')-1]) return false;
                    map[(c-'0')-1] = true;
                }
            }
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
