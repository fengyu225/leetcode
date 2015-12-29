/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0].
*/

#include "header.h"

class S_Node{
    public:
        int l, r, count;
        S_Node* left, *right;
        S_Node(int l, int r):l(l),r(r),count(0),left(NULL),right(NULL) {};
};

S_Node* build_tree(int l, int r){
    S_Node* root = new S_Node(l, r);
    if(l == r) return root;
    int m = l+(r-l)/2;
    root->left = build_tree(l, m);
    root->right = build_tree(m+1, r);
    return root;
}

void update(S_Node* root, int m){
    if(root->l == root->r) root->count++;
    else{
        int x = root->l+(root->r-root->l)/2;
        if(m<=x) update(root->left, m);
        else update(root->right, m);
        root->count++;
    }
}

int count_smaller(S_Node* root, int m){
    if(!root) return 0;
    int mid = root->l+(root->r-root->l)/2;
    if(mid<m) return root->left->count + count_smaller(root->right, m);
    else return count_smaller(root->left, m);
}

vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return vector<int>();
    vector<int> res(sz, 0);
    int min_val = std::min_element(nums.begin(), nums.end());
    int max_val = std::max_element(nums.begin(), nums.end());
    S_Node* root = build_tree(min_val, max_val); 
    for(int i=sz-1; i>=0; i--){
        update(root, nums[i]);
        res[i] = count_smaller(root, nums[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);
    print_vector<int>(res);
    return 0;
}