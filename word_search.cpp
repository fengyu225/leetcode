#include "header.h"

bool exist(vector<vector<char> > &board, string word) {
    queue<pair<int,int> > q;
    int x_l = board.size(), y_l = board[0].size();
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == word[0]){
                pair<int,int> pr = make_pair(i,j);
                q.push(pr);
            }
        }
    if(word.size() == 1) return !q.empty();
    queue<pair<int,int> > q_next;
    queue<pair<int,int> > q_arr[2]={q,q_next};
    int curr=0;
    int pos = 0;
    int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while(1){
        if(q_arr[curr].empty()) break;
        while(!q_arr[(curr+1)%2].empty()) q_arr[(curr+1)%2].pop();
        pos++;
        if(pos == word.size()) break;
        while(!q_arr[curr].empty()){
            pair<int,int> t = q_arr[curr].front();
            q_arr[curr].pop();
            for(int i=0; i<4; i++){
                int new_x = t.first+move[i][0];
                int new_y = t.second+move[i][1];
                if(new_x>=0 && new_x<x_l && new_y>=0 && new_y<y_l){
                    if(board[new_x][new_y] == word[pos]){
                        if(pos == word.size()-1)
                            return true;
                        else
                            q_arr[(curr+1)%2].push(make_pair(new_x,new_y));
                    }
                }
            }
        }
        curr = (curr+1)%2;
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
