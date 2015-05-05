#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            res.push_back(curr->val);
            curr = curr->right;
            continue;
        }
        TreeNode* x = curr->left;
        while(x->right && x->right != curr) x = x->right;
        if(x->right == curr){
            x->right = NULL;
            res.push_back(curr->val);
            curr = curr->right;
        }
        else{
            x->right = curr;
            curr = curr->left;
        }
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            res.push_back(curr->val);
            curr = curr->right;
            continue;
        }
        TreeNode* x = curr->left;
        while(x->right && x->right != curr) x = x->right;
        if(x->right == curr){
            x->right = NULL;
            curr = curr->right;
        }
        else{
            x->right = curr;
            res.push_back(curr->val);
            curr = curr->left;
        }
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    TreeNode* curr = root;

}

int main(){
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    one.left = &two;
    two.left = &three;
    //vector<int> res = inorderTraversal(&one);
    vector<int> res = preorderTraversal(&one);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
