#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void search(TreeNode* curr, int& res, int len_path_from_root){
    if(!curr->left && !curr->right){
        res = std::max(res,len_path_from_root+1);
        return;
    }
    if(curr->left)
        search(curr->left,res,len_path_from_root+1);
    if(curr->right)
        search(curr->right,res,len_path_from_root+1);
}

int maxDepth(TreeNode *root) {
    if(!root) return 0;
    int res = 1, curr=1;
    search(root,res,0);
    return res;
}

int main(){
    TreeNode n0(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n4.left = &n5;
    int res = maxDepth(&n0);
    printf("%d\n", res);
    return 0;
}
