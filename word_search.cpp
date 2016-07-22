/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include "header.h"

bool search(int r, int c, string& word, string& curr, vector<vector<char> >& board){
    if(curr.length()>=word.length()) return false;
    int c_len = curr.length();
    if(board[r][c] != word[c_len]) return false;
    char c_chr = board[r][c];
    curr+=c_chr;
    if(curr == word) return true;
    board[r][c] = '#';
    int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<4; i++){
        int new_r = r+move[i][0];
        int new_c = c+move[i][1];
        if(new_r>=0 && new_r<board.size() && new_c>=0 && new_c<board[0].size() && board[new_r][new_c] != '#'){
            if(search(new_r, new_c, word, curr, board)) return true;
        }
    }
    board[r][c] = c_chr;
    curr.pop_back();
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    int r = board.size();
    if(r == 0) return false;
    int c = board[0].size();
    for(int i=0; i<r; i++){
        for(int j=0;j<c;j++){
            string temp = "";
            bool res = search(i, j, word, temp, board);
            if(res) return true; 
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
//    string w1("SEE");
//    string w2("ABCB");
    printf("%s\n", exist(board,w0)?"true":"false");
//    printf("%s\n", exist(board,w1)?"true":"false");
//    printf("%s\n", exist(board,w2)?"true":"false");
    return 0;
}
