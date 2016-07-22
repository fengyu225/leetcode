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

class Node{
    public:
        Node(char c):val(c){
            memset(children, 0, sizeof(children));
        }
        Node* getChildren(char x){
            return this->children[x-'a'];
        } 
        Node* insert(char x){
            Node* n = new Node(x);
            this->children[x-'a'] = n;
            return n;
        }
        char getVal(){
            return this->val;
        }
    private:
        char val;
        Node* children[27]; 
};

class WordDictionary {
public:
    WordDictionary(){
        this->root = new Node(' ');     
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        Node* curr = this->root;
        for(auto c:word){
            Node* n = curr->getChildren(c);
            if(n) curr = n;
            else curr = curr->insert(c);
        }
        curr->insert('a'+26);
    }

    bool search(string& word, int x, Node* curr){
        if(!curr) return false;
        if(x == word.length()) return curr->getChildren('a'+26)!=NULL; 
        bool res = false;
        if(word[x] == '.'){
            for(int i=0; i<26; i++)
                res |= search(word, x+1, curr->getChildren('a'+i));
        }
        else res = search(word, x+1, curr->getChildren(word[x]));
        return res;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, this->root);
    }
private:
    Node* root;
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