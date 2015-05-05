#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    if(!root) return res;
    vector<int> curr_level;
    queue<TreeNode*> q_arr[2];
    queue<TreeNode*> curr;
    curr.push(root);
    queue<TreeNode*> next;
    q_arr[0] = curr;
    q_arr[1] = next;
    int x = 0;
    while(!q_arr[x%2].empty()){
        TreeNode* curr_n = q_arr[x%2].front();
        q_arr[x%2].pop();
        if(curr_n->left)
            q_arr[(x+1)%2].push(curr_n->left);
        if(curr_n->right)
            q_arr[(x+1)%2].push(curr_n->right);
        curr_level.push_back(curr_n->val);
        if(q_arr[x%2].empty()){
            res.push_back(curr_level);
            x++;
            curr_level.clear();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    TreeNode n0(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    vector<vector<int> > r = levelOrderBottom(&n0);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
