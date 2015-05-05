#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//vector<int> postorderTraversal(TreeNode *root) {
//    vector<int> res;
//    if(!root) return res;
//    stack<TreeNode*> s;
//    stack<TreeNode*> s_t;
//    s.push(root);
//    while(!s.empty()){
//        TreeNode* t = s.top();
//        s_t.push(t);
//        s.pop();
//        if(t->left){
//            s.push(t->left);
//        }
//        if(t->right){
//            s.push(t->right);
//        }
//    }
//    while(!s_t.empty()){
//        res.push_back(s_t.top()->val);
//        s_t.pop();
//    }
//    return res;
//}


vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    TreeNode* prev = NULL;
    TreeNode* curr = root;
    stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()){
        curr = stack.top();
        if(!prev || prev->left == curr || prev->right == curr){
            if(curr->left)
                stack.push(curr->left);
            else if(curr->right)
                stack.push(curr->right);
            else{
                res.push_back(curr->val);
                stack.pop();
            }
        }
        else if(curr->left == prev){
            if(curr->right)
                stack.push(curr->right);
            else{
                res.push_back(curr->val);
                stack.pop();
            }
        }
        else if(curr->right == prev){
            res.push_back(curr->val);
            stack.pop();
        }
        prev = curr;
    }
    return res;
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n5.left = &n7;
    n5.right = &n8;
    n6.left = &n9;
    vector<int> res = postorderTraversal(&n1);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
