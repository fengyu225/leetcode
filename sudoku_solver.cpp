#include "header.h"

bool is_valid(vector<vector<char> >& board, int r, int c){
    int arr[10];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<board[0].size(); i++){
        if(board[r][i] == '.') continue;
        if(arr[board[r][i]-'0'] != 0) return false;
        arr[board[r][i]-'0']++;
    }
    memset(arr,0,sizeof(arr));
    for(int i=0; i<board.size(); i++){
        if(board[i][c] == '.') continue;
        if(arr[board[i][c]-'0'] !=0) return false;
        arr[board[i][c]-'0']++;
    }
    memset(arr,0,sizeof(arr));
    for(int i=0; i<9; i++){
        int x = r/3+i/3;
        int y = c/3+i%3;
        if(board[x][y] == '.') continue;
        if(arr[board[x][y]-'0'] != 0) return false;
        arr[board[x][y]-'0'] = 1;
    }
    return true;
}

bool solve(vector<vector<char> >& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] != '.') continue;
            for(int k=1; k<10; k++){
                board[i][j] = (char)(k+'0');
                if(is_valid(board,i,j) && solve(board))
                    return true;
                board[i][j] = '.';
            }
            return false;
        }
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
