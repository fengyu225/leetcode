#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumNumbers(TreeNode* root, vector<int>& v, int& r){
    if(!root->left && !root->right){
        int x=0;
        for(int i=0; i<v.size(); i++) x = 10*x+v[i];
        r+=x;
        return;
    }
    if(root->left){
        v.push_back(root->left->val);
        sumNumbers(root->left, v, r);
        v.pop_back();
    }
    if(root->right){
        v.push_back(root->right->val);
        sumNumbers(root->right, v, r);
        v.pop_back();
    }
}

int sumNumbers(TreeNode* root){
    vector<int> v;
    int r=0;
    if(!root)
        return r;
    v.push_back(root->val);
    sumNumbers(root, v, r);
    return r;
}

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;
    printf("%d\n", sumNumbers(&t1));
    return 0;
}
