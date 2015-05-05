#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* sorted_array_to_bst(vector<int>& num, int l, int r){
    if(l>r) return NULL;
    int m = (l+r)/2;
    TreeNode* root = new TreeNode(num[m]); 
    root->left = sorted_array_to_bst(num,l,m-1);
    root->right = sorted_array_to_bst(num,m+1,r);
    return root;
}


TreeNode* sortedArrayToBST(vector<int> &num) {
    return sorted_array_to_bst(num,0,num.size()-1);
}

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = sortedArrayToBST(num);
    pre_order(root);
    printf("\n");
    return 0;
}
