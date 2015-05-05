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
    stack<TreeNode*> s_t;
    s.push(root);
    while(!s.empty()){
        TreeNode* t = s.top();
        s_t.push(t);
        s.pop();
        if(t->left){
            s.push(t->left);
        }
        if(t->right){
            s.push(t->right);
        }
    }
    while(!s_t.empty()){
        res.push_back(s_t.top()->val);
        s_t.pop();
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
