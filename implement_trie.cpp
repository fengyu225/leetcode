/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include "header.h"

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c):val(c) {}
    TrieNode():val(0) {}
    TrieNode* addChild(char c){
        TrieNode* n = new TrieNode(c);
        this->children[c] = n;
        return n;
    }
    bool inChildren(char c){
        return this->children.find(c) != this->children.end();
    }
    bool isLeaf(){
        return this->children.size() == 0; 
    }
    TrieNode* getChild(char c){
        if(!inChildren(c))  return NULL;
        return this->children[c];
    }
private:
    char val;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* curr = root;
        for(int i=0; i<s.length(); i++){
            if(curr->inChildren(s[i])) curr = curr->getChild(s[i]);
            else curr=curr->addChild(s[i]);
        }
        curr->addChild('#');
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* curr = root;
        for(int i=0; i<key.length(); i++){
            if(!curr->inChildren(key[i])) return false;
            curr = curr->getChild(key[i]);
        }
        return curr->inChildren('#');
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.length(); i++){
            if(!curr->inChildren(prefix[i])) return false;
            curr = curr->getChild(prefix[i]);
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