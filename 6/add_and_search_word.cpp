/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include "header.h"

class TrieNode{
    char val;
    unordered_map<char,TrieNode*> children;
    public:
        TrieNode(char c){
            val = c;
        }
        TrieNode* getChild(char c){
            return this->children[c];
        }
        TrieNode* addChild(char c){
            TrieNode* res = getChild(c);
            if(res != NULL) return res;
            res = new TrieNode(c);
            this->children[c] = res;
            return res;
        }
};

class Trie{
    TrieNode* root;
    bool search(string word, int curr, TrieNode* curr_n){
        int sz = word.length();
        if(curr == sz) return curr_n->getChild('$') != NULL;
        if(word[curr] != '.'){
            TrieNode* n = curr_n->getChild(word[curr]);
            if(n == NULL) return false;
            return search(word, curr+1, n);
        }
        for(char x = 'a'; x<='z'; x++){
            TrieNode* n = curr_n->getChild(x);
            if(n != NULL){
                bool res = search(word, curr+1, n);
                if(res) return true;
            }
        }
        return false;
    }
    public:
        Trie(){
            root = new TrieNode('^');
        }
        void insert(string word){
            TrieNode* curr = root;
            for(char c:word){
                curr = curr->addChild(c);
            }
            curr->addChild('$');
        }
        bool search(string word){
            return search(word, 0, root);  
        }
};

class WordDictionary {
    Trie t;
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        t.insert(word);     
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return t.search(word); 
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main(){
    WordDictionary wordDict;
    wordDict.addWord("word");
    cout<<wordDict.search("pattern")<<endl;
    wordDict.addWord("bad");
    wordDict.addWord("dad");
    wordDict.addWord("mad");
    cout<<wordDict.search("pad")<<endl;
    cout<<wordDict.search("bad")<<endl;
    cout<<wordDict.search(".ad")<<endl;
    cout<<wordDict.search("b..")<<endl;
    return 0;
}