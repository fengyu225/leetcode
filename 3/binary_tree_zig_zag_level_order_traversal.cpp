#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res;
    if(!root) return res;
    stack<TreeNode*> stack_curr;
    stack_curr.push(root);
    stack<TreeNode*> stack_next;
    stack<TreeNode*> stack_arr[2] = {stack_curr,stack_next};
    int curr = 0;
    bool left2right = true;
    vector<int> level_ns;
    while(!stack_arr[curr].empty()){
        TreeNode* curr_n = stack_arr[curr].top();
        stack_arr[curr].pop();
        level_ns.push_back(curr_n->val);
        if(left2right){
            if(curr_n->left)
                stack_arr[(curr+1)%2].push(curr_n->left);
            if(curr_n->right)
                stack_arr[(curr+1)%2].push(curr_n->right);
        }
        else{
            if(curr_n->right)
                stack_arr[(curr+1)%2].push(curr_n->right);
            if(curr_n->left)
                stack_arr[(curr+1)%2].push(curr_n->left);
        }
        if(stack_arr[curr].empty()){
            res.push_back(level_ns);
            level_ns.clear();
            curr = (curr+1)%2;
            left2right = !left2right;
        }
    }
    return res;
}

int main(){
    TreeNode n0(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(7);
    TreeNode n5(8);
    TreeNode n6(10);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n5;
    n1.right = &n6;
    n2.left = &n3;
    n2.right = &n4;
    vector<vector<int> > res = zigzagLevelOrder(&n0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
