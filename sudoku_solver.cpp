#include "header.h"

bool is_valid(vector<vector<char> >& board, int i, int j){
    //i row, j column
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int arr1[10] = {0,0,0,0,0,0,0,0,0,0};
    int arr2[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int a=0;a<board[i].size();a++){
        if(board[i][a] == '.') continue;
        int x = board[i][a]-'0';
        if(arr[x] != 0){
            return false;
        }
        arr[x] = 1;
    }
    for(int a=0; a<board.size(); a++){
        if(board[a][j] == '.') continue;
        int x = board[a][j]-'0';
        if(arr1[x] != 0){
            return false;
        }
        arr1[x] = 1;
    }
    for(int a=i/3*3;a<i/3*3+3;a++){
        for(int b=j/3*3;b<j/3*3+3;b++){
            if(board[a][b] == '.') continue;
            int x = board[a][b]-'0';
            if(arr2[x] != 0){
                return false;
            }
            arr2[x] = 1;
        }
    }
    return true;
}

bool solve(vector<vector<char> >& board){
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] != '.') continue;
            for(int k=1; k<10; k++){
                board[i][j] = (char)(k+'0');
                if(is_valid(board,i,j) && solve(board)){
                    return true;
                }
                board[i][j] = '.';
            }
            return false;
        }
    return true;
}

void solveSudoku(vector<vector<char> > &board) {
    if(board.size() == 0 || board[0].size() == 0) return;
    solve(board);
}

int main(){
    char arr0[] = "53..7....";
    char arr1[] = "6..195...";
    char arr2[] = ".98....6.";
    char arr3[] = "8...6...3";
    char arr4[] = "4..8.3..1";
    char arr5[] = "7...2...6";
    char arr6[] = ".6....28.";
    char arr7[] = "...419..5";
    char arr8[] = "....8..79";
    vector<char> v0(arr0,arr0+sizeof(arr0)/sizeof(char)-1);
    vector<char> v1(arr1,arr1+sizeof(arr1)/sizeof(char)-1);
    vector<char> v2(arr2,arr2+sizeof(arr2)/sizeof(char)-1);
    vector<char> v3(arr3,arr3+sizeof(arr3)/sizeof(char)-1);
    vector<char> v4(arr4,arr4+sizeof(arr4)/sizeof(char)-1);
    vector<char> v5(arr5,arr5+sizeof(arr5)/sizeof(char)-1);
    vector<char> v6(arr6,arr6+sizeof(arr6)/sizeof(char)-1);
    vector<char> v7(arr7,arr7+sizeof(arr7)/sizeof(char)-1);
    vector<char> v8(arr8,arr8+sizeof(arr8)/sizeof(char)-1);
    vector<vector<char> > board;
    board.push_back(v0);
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    board.push_back(v5);
    board.push_back(v6);
    board.push_back(v7);
    board.push_back(v8);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
    solveSudoku(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return 0;
}
