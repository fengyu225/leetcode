#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> build(int l, int r){
    vector<TreeNode*> res;
    if(l>r){
        res.push_back(NULL);
        return res;
    }
    if(l == r){
        res.push_back(new TreeNode(l));
        return res;
    }
    for(int i=l;i<=r;i++){
        vector<TreeNode*> left_v = build(l,i-1);
        vector<TreeNode*> right_v = build(i+1,r);
        for(int j=0;j<left_v.size();j++)
            for(int k=0;k<right_v.size();k++){
                TreeNode* cr = new TreeNode(i);
                cr->left = left_v[j];
                cr->right = right_v[k];
                res.push_back(cr);
            }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res = build(1,n);
    return res;
}

void dfs(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    dfs(root->left);
    dfs(root->right);
}

int main(){
    vector<TreeNode*> res = generateTrees(4);
    for(int i=0;i<res.size();i++){
        dfs(res[i]);
        printf("\n");
    }
    return 0;
}
