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

class SegmentTreeNode {
    public:
        int max;
        int start, end;
        SegmentTreeNode* left, *right;
        SegmentTreeNode(int s, int e):max(0),start(s),end(e),left(NULL),right(NULL) {}
};

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void printSegmentTree(SegmentTreeNode* root);

ListNode* create_list(int arr[], int n);
ListNode* create_list(vector<int> nums);

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

class TrieNode {
public:
    TrieNode(char c):val(c) {} 
    TrieNode():val(0) {}
    TrieNode* addChild(char c);
    bool inChildren(char c);
    bool isLeaf();
    TrieNode* getChild(char c);
private:
    char val;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s);
    bool search(string key);
    bool startsWith(string prefix);
    TrieNode* getRoot();
private:
    TrieNode* root;
};

void print_arr(vector<int>& nums, int l, int r);

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class NestedInteger {
  bool is_integer;
  int val;
  vector<NestedInteger> val_list;
  public:
    NestedInteger(int v){
    	val = v;
	is_integer = true;
    }
    NestedInteger(){
    	is_integer = false;
    }
    bool isInteger() const;
    int getInteger() const;
    vector<NestedInteger> &getList();
    void addNextedInteger(NestedInteger n);
};
