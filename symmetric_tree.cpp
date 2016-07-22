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

/* using recursion
bool check(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(left && right)
        return left->val==right->val && check(left->left, right->right) && check(left->right, right->left);
    return false;
}

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return check(root->left, root->right);
}
*/

bool check(vector<string>& v){
    int l=0, r=v.size()-1;
    while(l<r){
        if(v[l] != v[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    queue<TreeNode*> curr_q;
    queue<TreeNode*> next_q;
    curr_q.push(root);
    queue<TreeNode*> qs[2] = {curr_q, next_q};
    vector<string> v;
    int x = 0;
    while(!qs[x%2].empty()){
        TreeNode* temp = qs[x%2].front();
        qs[x%2].pop();
        if(temp->left){
            qs[(x+1)%2].push(temp->left);
            v.push_back(to_string(temp->left->val));
        }
        else v.push_back("#");
        if(temp->right){
            qs[(x+1)%2].push(temp->right);
            v.push_back(to_string(temp->right->val));
        }
        else v.push_back("#");
        if(qs[x%2].empty()){
            if(!check(v)) return false;
            v.clear();
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