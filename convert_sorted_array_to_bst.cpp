#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& num, int start, int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(num[mid]);
    root->left = sortedArrayToBST(num, start, mid-1);
    root->right = sortedArrayToBST(num, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int> &num) {
    return sortedArrayToBST(num, 0, num.size()-1);
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
