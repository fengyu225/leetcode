#include "stdlib.h"
#include <string> 
#include <vector>

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

TreeNode* create_tree(std::string v);
TreeNode* create_tree(std::vector<std::string> v);

void pre_order(TreeNode* root);

class TreeLinkNode {
    public:
        TreeLinkNode *left;
        TreeLinkNode *right;
        TreeLinkNode *next;
        int val;
        TreeLinkNode(int v):left(NULL),right(NULL),next(NULL),val(v) {}
};

TreeLinkNode* create_link_tree(std::vector<std::string> v);
