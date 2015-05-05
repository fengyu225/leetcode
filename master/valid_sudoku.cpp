#include "header.h"

bool isValidSudoku(vector<vector<char> > &board) {
    int arr[9] = {0};
    for(int i=0; i<9; i++){
        memset(arr,0,sizeof(arr));
        for(int j=0; j<9; j++){
            char c = board[i][j];
            if(c == '.') continue;
            else if(arr[(c-'0')-1] != 0)
                return false;
            else
                arr[(c-'0')-1] = 1;
        }
    }
    for(int i=0; i<9; i++){
        memset(arr,0,sizeof(arr));
        for(int j=0; j<9; j++){
            char c = board[j][i];
            if(c == '.') continue;
            else if(arr[(c-'0')-1] != 0)
                return false;
            else
                arr[(c-'0')-1] = 1;
        }
    }
    for(int i=0; i<9; i++){
        int row = i/3*3;
        int col = i%3*3;
        memset(arr,0,sizeof(arr));
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                char c = board[i][j];
                if(c=='.') continue;
                else if(arr[(c-'0')-1] != 0)
                    return false;
                else
                    arr[(c-'0')-1] = 1;
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
