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

int move[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

void search(vector<vector<char> >& board, Trie& t, int i, int j, unordered_set<string>& st, TrieNode* curr){
    char orig_c = board[i][j];
    board[i][j] = 'X'; 
    if(curr->)
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    if(words.size() == 0 || board.size() == 0 || board[0].size() == 0) return 0;
    vector<string> res;
    unordered_set<string> st;
    Trie t;
    for(string s:words) t.insert(s);
    int r = board.size(), c = board[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            TrieNode* r = t.getRoot();
            search(board, t, i, j, st, r);
        }
    }
    for(auto s:st) res.push_back(s);
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