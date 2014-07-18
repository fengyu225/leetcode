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
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* t = st.top();
        if(t->left){
            st.push(t->left);
            continue;
        }
        while(!st.empty() && st.top()->right == NULL){
            res.push_back(st.top()->val);
            st.pop();
        }
        if(!st.empty()){
            t = st.top();
            res.push_back(t->val);
            st.pop();
            st.push(t->right);
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
