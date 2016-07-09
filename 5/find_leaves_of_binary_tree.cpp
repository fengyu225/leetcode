/*
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:
          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:
          1          
3. Now removing the leaf [1] would result in the empty tree:
          []         
Returns [4, 5, 3], [2], [1].
*/

#include "header.h"

//vector<int> merge(vector<int>& a, vector<int>& b){
//    vector<int> res;
//    for(int i:a) res.push_back(i);
//    for(int i:b) res.push_back(i);
//    return res;
//}
//
//vector<vector<int>> findLeaves(TreeNode* root) {
//    vector<vector<int> > res;
//    if(!root) return res;
//    vector<vector<int> > left = findLeaves(root->left);
//    vector<vector<int> > right = findLeaves(root->right);
//    for(int l = 0, r = 0; l<left.size() || r<right.size(); ){
//        if(l<left.size() && r<right.size()){
//            res.push_back(merge(left[l], right[r]));
//            l++;
//            r++;
//        }
//        else if(l == left.size()) res.push_back(right[r++]);
//        else res.push_back(left[l++]); 
//    }
//    res.push_back(vector<int>(1, root->val));
//    return res;
//}

int findLeaves(TreeNode* root, vector<vector<int> >& res){
    if(!root) return -1;
    if(root->left == NULL && root->right == NULL){
        if(res.size() == 0) res.push_back(vector<int>(1, root->val));
        else res[0].push_back(root->val);
        return 0;
    }
    int l = findLeaves(root->left, res);
    int r = findLeaves(root->right, res);
    int level = max(l, r)+1;
    if(level >= res.size()) res.push_back(vector<int>(1, root->val));
    else res[level].push_back(root->val);
    return level;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int> > res;
    findLeaves(root, res);
    return res;
}

int main(){
    TreeNode* root = create_tree("12345");
    vector<vector<int> > res = findLeaves(root);
    for(auto v : res)
        print_vector<int>(v);
    return 0;
}
