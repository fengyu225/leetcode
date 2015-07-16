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

void search(vector<vector<char> >& board, int i, int j, unordered_set<string>& res, TrieNode* curr_n, string& temp){
    if(!curr_n) return;
    if(!curr_n->inChildren(board[i][j])) return;
    int move[4][2] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    string orig_temp = temp;
    temp.push_back(board[i][j]);
    char c = board[i][j];
    board[i][j] = 'X';
    TrieNode* orig_n = curr_n;
    curr_n = curr_n->getChild(c);
    if(curr_n->inChildren('#')){
        res.insert(temp);
    }
    for(int k=0; k<4; k++){
        int new_i = i+move[k][0];
        int new_j = j+move[k][1];
        if(new_i>=0 && new_i<board.size() && new_j>=0 && new_j<board[0].size() && board[new_i][new_j] != 'X')
            search(board, new_i, new_j, res, curr_n, temp);
    }
    board[i][j] = c;
    curr_n = orig_n;
    temp = orig_temp;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<string> res;
    unordered_set<string> set;
    if(words.size() == 0) return res;
    Trie trie;
    for(string w:words) trie.insert(w);
    int r = board.size(), c = board[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            string temp = "";
            TrieNode* curr_n = trie.getRoot(); 
            search(board, i, j, set, curr_n, temp);
        }
    }
    for(auto i=set.begin(); i!=set.end(); i++) res.push_back(*i);
    return res;
}

int main(){
    char c1[] = "a";
//    char c2[] = "etae";
//    char c3[] = "ihkr";
//    char c4[] = "iflv";
    vector<vector<char> > board;
    board.push_back(vector<char>(c1, c1+1));
//    board.push_back(vector<char>(c2, c2+4));
//    board.push_back(vector<char>(c3, c3+4));
//    board.push_back(vector<char>(c4, c4+4));
    vector<string> words;
    words.push_back("a");
//    words.push_back("oath");
//    words.push_back("pea");
//    words.push_back("eat");
//    words.push_back("rain");
    vector<string> res = findWords(board, words);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}