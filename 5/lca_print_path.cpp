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

TreeNode* lca_p(TreeNode* root, TreeNode* a, TreeNode* b, bool& found_a, bool& found_b){
    if(!root){
        found_a = found_b = false;
        return NULL;
    }
    if(root == a){
        found_a = true;
        found_b = false;
        cout<<root->val<<" ";
        return root;
    }    
    if(root == b){
        found_b = true;
        found_a = false;
        cout<<root->val<<" ";
        return root;
    }
    bool f_a_l = false, f_a_r = false, f_b_l = false, f_b_r = false;
    TreeNode* l = lca_p(root->left, a, b, f_a_l, f_b_l);
    TreeNode* r = lca_p(root->right, a, b, f_a_r, f_b_r);
    if((f_a_l || f_a_r || f_b_l || f_b_r) && !((f_a_l && f_b_l) || (f_a_r && f_b_r))) cout<<root->val<<" ";
    found_a = f_a_l || f_a_r;
    found_b = f_b_l || f_b_r;
    if(l && r) return root;
    return l?l:r;
}

void lca_print_path(TreeNode* root, TreeNode* a, TreeNode* b){
    bool found_a = false, found_b=false;
    lca_p(root,a,b,found_a,found_b);
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
