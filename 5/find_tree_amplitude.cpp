/*
一颗binary tree中，从上往下任意两个node可以组成一条path，一条path的amplitude是指这条path中最大数和最小数的差。求这颗树的amplitude(也就是所有path的最大的那个amplitude)
*/

#include "header.h"

void search(TreeNode* root, int& max_val, int& min_val, int&res){
    if(!root) return;
    int l_max = root->val, l_min = root->val, r_max = root->val, r_min = root->val, l_res = 0, r_res = 0;
    search(root->left, l_max, l_min, l_res);
    search(root->right, r_max, r_min, r_res);
    int curr_res = max(
                max(
                    l_max - root->val,
                    root->val - l_min
                    ),
                max(
                    r_max - root->val,
                    root->val - r_min
                    )
            );
    res = max(curr_res, max(l_res, r_res));
    max_val = max(max(l_max, r_max), root->val);
    min_val = min(min(l_min, r_min), root->val);
}

int getAmplitude(TreeNode* root){
    if(!root) return 0;
    int max_val = root->val, min_val = root->val, res = 0;
    search(root, max_val, min_val, res);
    return res;
}

int main(){
    string arr[] = {"0","-1","2","3","40","5"};
    TreeNode* root = create_tree(vector<string>(arr, arr+sizeof(arr)/sizeof(arr[0])));
    cout<<getAmplitude(root)<<endl;
    return 0;
}