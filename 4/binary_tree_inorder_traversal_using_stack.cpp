#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr = s.top();
        if(curr->left){
            s.push(curr->left);
            continue;
        }
        while(!s.empty() && !s.top()->right){
            res.push_back(s.top()->val);
            s.pop();
        }
        if(!s.empty()){
            curr = s.top();
            res.push_back(curr->val);
            s.pop();
            s.push(curr->right);
        }
    }
    return res;
}

int main(){
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    one.right = &two;
    two.left = &three;
    vector<int> res = inorderTraversal(&one);
//    three.left = &one;
//    three.right = &two;
//    vector<int> res = postorderTraversal(&three);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
