#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> s;
    TreeNode* curr,*pre;
    pre = NULL;
    s.push(root);
    while(!s.empty()){
        curr = s.top();
        if(!pre || pre->left == curr || pre->right == curr){
            if(curr->left){
                s.push(curr->left);
            }
            else if(curr->right){
                s.push(curr->right);
            }
            else{
                res.push_back(curr->val);
                s.pop();
            }
        }
        else if(curr->left==pre){
            if(curr->right){
                s.push(curr->right);
            }
            else{
                res.push_back(curr->val);
                s.pop();
            }
        }
        else if(curr->right == pre){
            res.push_back(curr->val);
            s.pop();
        }
        pre = curr;
    }
    return res;
}

int main(){
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    three.left = &one;
    three.right = &two;
    vector<int> res = postorderTraversal(&three);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
