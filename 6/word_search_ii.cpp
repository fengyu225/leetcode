/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include "header.h"

void search(vector<vector<char> >& board, int i, int j, unordered_set<string>& st, TrieNode* curr, string& temp_str, int row, int col, int max_len, int curr_len){
    TrieNode* next_curr = curr->getChild(board[i][j]);
    if(next_curr == NULL || curr_len>max_len || curr->count == 0) return;
    //cout<<board[i][j]<<endl;
    int move[4][2] = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };
    char orig_c = board[i][j];
    board[i][j] = 'X'; 
    temp_str.push_back(orig_c);
    if(next_curr->getChild('a'+27) != NULL) st.insert(temp_str);
    for(int k=0; k<4; k++){
        int new_x = i+move[k][0], new_y = j+move[k][1];
        if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && board[new_x][new_y] != 'X' && next_curr->count>0)
            search(board, new_x, new_y, st, next_curr, temp_str, row, col, max_len, curr_len+1);
    }
    board[i][j] = orig_c;
    temp_str.pop_back();
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<string> res;
    if(words.size() == 0 || board.size() == 0 || board[0].size() == 0) return res;
    unordered_set<string> st;
    Trie t;
    int max_len = 0;
    for(string s:words){
        t.insert(s);
        max_len = max(max_len, (int)s.length());
    }
    int r = board.size(), c = board[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            TrieNode* t_n = t.getRoot();
            string temp_str = "";
            search(board, i, j, st, t_n, temp_str, r, c, max_len, 0);
        }
    }
    for(auto s:st) res.push_back(s);
    return res;
}

int main(){
    vector<vector<char> > board = {
  {'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = findWords(board, words);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}