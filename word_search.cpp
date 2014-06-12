#include "header.h"

bool exist(vector<vector<char> > &board, string word) {
    queue<pair<int,int> > q;
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == word[0]){
                pair<int,int> pr = make_pair(i,j);
                q.push(pr);
            }
        }
    queue<pair<int,int> > q_next;
    queue<pair<int,int> > q_arr[2]={q,q_next};
    int curr=0;
    int pos = 0;
    while(!q.empty()){
        pair<int,int> t = q.front();
        if t
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
