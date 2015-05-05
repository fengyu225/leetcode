#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build(int l, int r,vector<TreeNode*>& res){
    if(l>r){
        res.push_back(NULL);
        return;
    }
    for(int i=l;i<=r;i++){
        vector<TreeNode*> left_v;
        vector<TreeNode*> right_v;
        build(l,i-1,left_v);
        build(i+1,r,right_v);
        for(int j=0;j<left_v.size();j++)
            for(int k=0;k<right_v.size();k++){
                TreeNode* cr = new TreeNode(i);
                cr->left = left_v[j];
                cr->right = right_v[k];
                res.push_back(cr);
            }
    }
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    build(1,n,res);
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
