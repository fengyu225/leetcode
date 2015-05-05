#include<stdlib.h>
#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    stack<vector<int> > s;
    vector<vector<int> > result;
    if(!root) return result;
    queue<TreeNode*> q_curr;
    queue<TreeNode*> q_next;
    queue<TreeNode*> qs[2] = {q_curr,q_next};
    int curr=0;
    qs[curr].push(root);
    vector<int> v;
    while(!qs[curr].empty()){
        while(!qs[curr].empty()){
            TreeNode* x = qs[curr].front();
            v.push_back(x->val);
            if(x->left)
                qs[(curr+1)%2].push(x->left);
            if(x->right)
                qs[(curr+1)%2].push(x->right);
            qs[curr].pop();
        }
        s.push(v);
        v.clear();
        curr = (curr+1)%2;
    }
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
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
