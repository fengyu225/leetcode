#include "header.h"

bool dfs(vector<vector<char> >& board, string word, int pos, int x, int y){
    if(pos == word.size()) return true;
    int move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for(int i=0; i<4; i++){
        int new_x = x+move[i][0];
        int new_y = y+move[i][1];
        if(new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size()){
            if(board[new_x][new_y] == word[pos]){
                char temp_c = board[new_x][new_y];
                board[new_x][new_y] = '#';
                bool r = dfs(board,word,pos+1,new_x,new_y);
                board[new_x][new_y] = temp_c;
                if(r) return true;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if(word.size() == 0) return false;
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == word[0]){
                char temp_c = word[0];
                board[i][j] = '#';
                bool r = dfs(board,word,1,i,j);
                board[i][j] = temp_c;
                if(r) return true;
            }
        }
    return false;
}

int main(){
    char s0[]="ABCE";
    char s1[]="SFCS";
    char s2[]="ADEE";
    vector<char> vs0(s0,s0+strlen(s0));
    vector<char> vs1(s1,s1+strlen(s1));
    vector<char> vs2(s2,s2+strlen(s2));
    vector<vector<char> > board;
    board.push_back(vs0);
    board.push_back(vs1);
    board.push_back(vs2);
    string w0("ABCCED");
    string w1("SEE");
    string w2("ABCB");
    printf("%s\n", exist(board,w0)?"true":"false");
    printf("%s\n", exist(board,w1)?"true":"false");
    printf("%s\n", exist(board,w2)?"true":"false");
    return 0;
}
