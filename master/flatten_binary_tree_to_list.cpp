#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(TreeNode* root){
    if(!root) return NULL;
    TreeNode* left_end = dfs(root->left);
    TreeNode* right_end = dfs(root->right);
    if(root->right){
        if(root->left){
            left_end->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return right_end;
    }
    else if(root->left){
        root->right = root->left;
        root->left = NULL;
        return left_end;
    }
    else
        return root;
}

void flatten(TreeNode* root){
    dfs(root);
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    flatten(&n1);
    TreeNode* curr = &n1;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->right;
    }
    printf("\n");
    return 0;
}
