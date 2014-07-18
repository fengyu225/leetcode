#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* t = st.top();
        st.pop();
        res.push_back(t->val);
        if(t->right)
            st.push(t->right);
        if(t->left)
            st.push(t->left);
    }
    return res;
}

int main(){
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    one.right = &two;
    two.left = &three;
    vector<int> res = preorderTraversal(&one);
//    three.left = &one;
//    three.right = &two;
//    vector<int> res = postorderTraversal(&three);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
