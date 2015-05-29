#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//void lca_print_path(TreeNode* root, TreeNode* a, TreeNode* b){
//    if(!root) return NULL;
//    if(root == a || root == b) return root;
//    TreeNode* l = lca(root->left,a,b);
//    TreeNode* r = lca(root->right,a,b);
//    if(l && r) return root;
//    return l?l:r;
//}

TreeNode* lca_p(TreeNode* root, TreeNode* a, TreeNode* b, vector<int>& res, bool& found){
    if(!root){
        vector<int> temp;
        res = temp;
        return NULL;
    }
    if(root == a || root == b){
        res.push_back(root->val);
        if(a == b) found = true;
        return root;
    }
    vector<int> l_res;
    vector<int> r_res;
    TreeNode* l = lca_p(root->left, a, b, l_res, found);
    TreeNode* r = lca_p(root->right, a, b, r_res, found);
    if(l && r){
        vector<int> temp(l_res);
        temp.push_back(root->val);
        reverse(r_res.begin(), r_res.end());
        for(int i=0; i<r_res.size(); i++)
            temp.push_back(r_res[i]);
        res = temp;
        found = true;
        return root;
    }
    else{
        if(!found){
            if(l){
                l_res.push_back(root->val);
            }
            else{
                r_res.push_back(root->val);
            }
        }
        if(l || r) res = (l?l_res:r_res);
        return l?l:r;
    }
}

void lca_print_path(TreeNode* root, TreeNode* a, TreeNode* b){
    vector<int> res;
    bool found = false;
    lca_p(root,a,b,res,found);
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
    lca_print_path(&t0, &t3, &t7);
    return 0;
}
