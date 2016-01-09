/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include "header.h"

class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    char val;
    // Initialize your data structure here.
    TrieNode(char c) {
        val = c;
    }
    TrieNode* addChild(char c){
        TrieNode* res = getChild(c);
        if(res != NULL) return res;
        res = new TrieNode(c);
        this->children[c]=res;
        return res;
    }
    TrieNode* getChild(char c){
        return this->children[c];
    }
};

class Trie {
public:
    Trie() {
        this->root = new TrieNode('z'+1);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root, *next;
        for(char c:word){
            next = curr->addChild(c);
            curr = next;
        }
        curr->addChild('z'+2);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
        for(char c:word){
            TrieNode* next = curr->getChild(c);
            if(!next) return false;
            curr = next;
        }
        return curr->getChild('z'+2) != NULL;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c:prefix){
            TrieNode* next = curr->getChild(c);
            if(!next) return false;
            curr = next;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main(){
    Trie t;
    t.insert("abc");
    t.insert("abcd");
    cout<<t.search("abc")<<endl;
    cout<<t.startsWith("abd")<<endl;
    return 0;
}