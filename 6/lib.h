#include "stdlib.h"
#include <string> 
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode* create_list(int arr[], int n);

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MultiTreeNode {
    public:
        char c;
        vector<MultiTreeNode*> children;
        MultiTreeNode(char x) : c(x), children(vector<MultiTreeNode*>()) {}
};

TreeNode* create_tree(std::string v);
TreeNode* create_tree(std::vector<std::string> v);

void pre_order(TreeNode* root);
void in_order(TreeNode* root);

class TreeLinkNode {
    public:
        TreeLinkNode *left;
        TreeLinkNode *right;
        TreeLinkNode *next;
        int val;
        TreeLinkNode(int v):left(NULL),right(NULL),next(NULL),val(v) {}
};

TreeLinkNode* create_link_tree(std::vector<std::string> v);

class UndirectedGraphNode {
    public:
        int label;
        vector<UndirectedGraphNode*> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void print_random_list(RandomListNode* root);

ListNode* create_list(int arr[], int n, int s);

void print_list(ListNode*);

template<typename T>
void print_vector(vector<T> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}


template<typename T>
void print_2d_vector(vector<vector<T> > v){
    for(auto v_t:v){
        for(auto i:v_t) cout<<i<<"        ";
        cout<<endl;
    }
}

//class TrieNode {
//public:
//    unordered_map<char,TrieNode*> children;
//    char val;
//    // Initialize your data structure here.
//    TrieNode(char c) {
//        val = c;
//    }
//    TrieNode* addChild(char c){
//        TrieNode* res = getChild(c);
//        if(res != NULL) return res;
//        res = new TrieNode(c);
//        this->children[c]=res;
//        return res;
//    }
//    TrieNode* getChild(char c){
//        return this->children[c];
//    }
//};
//
//class Trie {
//public:
//    Trie() {
//        this->root = new TrieNode('^');
//    }
//
//    // Inserts a word into the trie.
//    void insert(string word) {
//        TrieNode* curr = root, *next;
//        for(char c:word){
//            next = curr->addChild(c);
//            curr = next;
//        }
//        curr->addChild('$');
//    }
//
//    // Returns if the word is in the trie.
//    bool search(string word) {
//        TrieNode* curr = root;
//        for(char c:word){
//            TrieNode* next = curr->getChild(c);
//            if(!next) return false;
//            curr = next;
//        }
//        return curr->getChild('$') != NULL;
//    }
//
//    // Returns if there is any word in the trie
//    // that starts with the given prefix.
//    bool startsWith(string prefix) {
//        TrieNode* curr = root;
//        for(char c:prefix){
//            TrieNode* next = curr->getChild(c);
//            if(!next) return false;
//            curr = next;
//        }
//        return true;
//    }
//    
//    TrieNode* getRoot(){
//        return root;
//    }
//private:
//    TrieNode* root;
//};

void print_arr(vector<int>& nums, int l, int r);

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class TrieNode {
public:
    vector<TrieNode*> children;
    char val;
    int count;
    // Initialize your data structure here.
    TrieNode(char c) {
        val = c;
        count = 0;
        children = vector<TrieNode*>(28, NULL);
    }
    TrieNode* addChild(char c){
        TrieNode* res = getChild(c);
        if(res != NULL) return res;
        res = new TrieNode(c);
        this->children[c-'a']=res;
        return res;
    }
    TrieNode* getChild(char c){
        return this->children[c-'a'];
    }
};

class Trie {
public:
    Trie() {
        this->root = new TrieNode('a'+26);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root, *next;
        for(char c:word){
            next = curr->addChild(c);
            curr->count++;
            curr = next;
        }
        curr->addChild('a'+27);
        curr->count++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
        for(char c:word){
            TrieNode* next = curr->getChild(c);
            if(!next) return false;
            curr = next;
        }
        return curr->getChild('a'+27) != NULL;
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
    
    TrieNode* getRoot(){
        return root;
    }
private:
    TrieNode* root;
};


