#include<stdlib.h>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

void bfs(vector<vector<char> >& board, int x, int y){
    queue<int> x_q;
    queue<int> y_q;
    x_q.push(x);
    y_q.push(y);
    int arr[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    board[x][y] = 'B';
    printf("mark (%d,%d)\n", x, y);
    while(!x_q.empty()){
        int t_x = x_q.front();
        int t_y = y_q.front();
        x_q.pop();
        y_q.pop();
        for(int i=0; i<3; i++)
                if(
                        t_x+arr[i][0]<board.size() && t_x+arr[i][0]>=0 &&
                        t_y+arr[i][1]<board[0].size() && t_y+arr[i][1] >=0 && 
                        board[t_x+arr[i][0]][t_y+arr[i][1]] == 'O'){
                    board[t_x+arr[i][0]][t_y+arr[i][1]] = 'B';
                    printf("mark (%d,%d)\n", t_x+arr[i][0], t_y+arr[i][1]);
                    x_q.push(t_x+arr[i][0]);
                    y_q.push(t_y+arr[i][1]);
                }
    }
}

void solve(vector<vector<char> >& board){
    if(board.size() == 0)
        return;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if((i==0 || i==board.size()-1 || j==0 || j == board[i].size()-1) && board[i][j] == 'O')
                bfs(board,i,j);
        }
    }
//    for(int i=0; i<board.size(); i++)
//        if(board[i][0] == 'O')
//            bfs(board,i,0);
//    for(int i=0; i<board.size(); i++)
//        if(board[i][board[i].size()-1] == 'O')
//            bfs(board,i,board[i].size()-1);
//    for(int i=0; i<board[0].size(); i++)
//        if(board[0][i] == 'O')
//            bfs(board,0,i);
//    for(int i=0; i<board[board.size()-1].size(); i++)
//        if(board[board.size()-1][i] == 'O')
//            bfs(board,board.size()-1,i);
//    for(int i=0; i<board.size(); i++)
//        for(int j=0; j<board[i].size(); j++){
//            if(board[i][j] == 'O') board[i][j] = 'X';
//            if(board[i][j] == 'B') board[i][j] = 'O';
//        }
}

int main(){
//    char s0[] = {'X','O','X','O', 'X', 'O'};
//    char s1[] = {'O','X','O','X', 'O', 'X'};
//    char s2[] = {'X','O','X','O', 'X', 'O'};
//    char s3[] = {'O','X','O','X', 'O', 'X'};
    char s0[] = "XOXOXO";
    char s1[] = "OXOXOX";
    char s2[] = "XOXOXO";
    char s3[] = "OXOXOX";
    vector<vector<char> > board;
    vector<char> v0(s0, s0+sizeof(s0)/sizeof(char));
    vector<char> v1(s1, s1+sizeof(s1)/sizeof(char));
    vector<char> v2(s2, s2+sizeof(s2)/sizeof(char));
    vector<char> v3(s3, s3+sizeof(s3)/sizeof(char));
    board.push_back(v0);
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    solve(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return 0;
}
