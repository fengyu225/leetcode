#include "header.h"
struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumNumbers(TreeNode* root, vector<int>& v, int& r){
    if(!root->left && !root->right){
        int x = 0;
        for(int i=0; i<v.size(); i++) x=10*x+v[i];
        r += 10*x+root->val;
        return;
    }
    v.push_back(root->val);
    if(root->left)
        sumNumbers(root->left,v,r);
    if(root->right)
        sumNumbers(root->right,v,r);
    v.pop_back();
}

int sumNumbers(TreeNode* root){
    vector<int> v;
    int r=0;
    if(!root)
        return r;
    sumNumbers(root, v, r);
    return r;
}

/*

                4
        /               \
        9               0
         \
          1 

*/

int main(){
    TreeNode t1(4);
    TreeNode t2(9);
    TreeNode t3(0);
    TreeNode t4(1);
    t1.left = &t2;
    t1.right = &t3;
    t2.right = &t4;
    printf("%d\n", sumNumbers(&t1));
    return 0;
}
