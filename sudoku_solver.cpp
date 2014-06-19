#include "header.h"

void solveSudoku(vector<vector<char> > &board) {
    
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
    vector<char> v0(arr0,arr0+sizeof(arr0)/sizeof(char));
    vector<char> v1(arr1,arr1+sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2,arr2+sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3,arr3+sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4,arr4+sizeof(arr4)/sizeof(char));
    vector<char> v5(arr5,arr5+sizeof(arr5)/sizeof(char));
    vector<char> v6(arr6,arr6+sizeof(arr6)/sizeof(char));
    vector<char> v7(arr7,arr7+sizeof(arr7)/sizeof(char));
    vector<char> v8(arr8,arr8+sizeof(arr8)/sizeof(char));
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
    solveSudoku(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return 0;
}
