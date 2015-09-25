/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

    1
   / \
  2   2
   \   \
   3    3
Bonus points if you could solve it both recursively and iteratively.
*/

#include "header.h"

//bool check(TreeNode* left, TreeNode* right){
//    if(!left && !right) return true;
//    if(left && right) return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
//    return false;
//}
//
//bool isSymmetric(TreeNode* root) {
//    if(!root) return false;
//    return check(root->left, root->right);
//}

bool check(vector<TreeNode*>& v){
    int sz = v.size();
    int l = 0, r = sz-1;
    while(l<r){
        if(!v[l] && v[r] || v[l] && !v[r]) return false;
        if(v[l] && v[r] && v[l]->val != v[r]->val) return false;
        l++;
        r--;
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    vector<TreeNode*> curr = {root};
    vector<TreeNode*> next;
    int x = 0;
    vector<TreeNode*> arr[2] = {curr, next};
    while(!arr[x%2].empty()){
        TreeNode* n = arr[x%2].front();
        if(n){
            arr[(x+1)%2].push_back(n->left);
            arr[(x+1)%2].push_back(n->right);
        }
        arr[x%2].erase(arr[x%2].begin());
        if(arr[x%2].empty()){
            if(!check(arr[(x+1)%2])) return false;
            x++;
        }
    }
    return true;
}

int main(){
    string arr_1[] = {"1","2","2","3","4","4","3"};
    vector<string> v_1(arr_1, arr_1+sizeof(arr_1)/sizeof(arr_1[0]));
    string arr_2[] = {"1","2","2","#","3","#","3"};
    vector<string> v_2(arr_2, arr_2+sizeof(arr_2)/sizeof(arr_2[0]));
    TreeNode* t1 = create_tree("1223443");
    TreeNode* t2 = create_tree("122#3#3");
    cout<<isSymmetric(t1)<<endl;
    cout<<isSymmetric(t2)<<endl;
    return 0;
}