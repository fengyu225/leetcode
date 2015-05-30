#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lca_p(TreeNode* root, TreeNode* a, TreeNode* b, vector<int>& path){
    if(!root) return 0;
    vector<int> l_path;
    vector<int> r_path;
    int l = lca_p(root->left, a, b, l_path);
    int r = lca_p(root->right, a, b, r_path);
    vector<int> temp;
    if(l == 2) path = l_path;
    else if(r == 2) path = r_path;
    else{
        if(l == 1) temp = l_path;
        if(l == 1 || r == 1 || root==a || root==b) temp.push_back(root->val);
        if(r == 1){
            reverse(r_path.begin(), r_path.end());
            for(int i=0; i<r_path.size(); i++) temp.push_back(r_path[i]);
        }
        path = temp;
    }
    return (root==a)+(root==b)+l+r;
}

void lca_print_path(TreeNode* root, TreeNode* a, TreeNode* b){
    vector<int> res;
    int x = lca_p(root,a,b,res);
    if(x==2)
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
    cout<<endl;
}

int main(){
    TreeNode t0(15);
    TreeNode t1(10);
    TreeNode t2(20);
    TreeNode t3(8);
    TreeNode t4(12);
    TreeNode t5(16);
    TreeNode t6(25);
    TreeNode t7(13);
    TreeNode t8(17);
    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    t4.right = &t7;
    t5.right = &t8;
    lca_print_path(&t0, &t6, &t5);
    return 0;
}
