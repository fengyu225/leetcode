/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,
       1
      / \
     2   3
Return 4.
*/

#include "header.h"

void search(TreeNode* root, int target, vector<int>& parents, vector<vector<int> >& res){
    if(!root) return;
    vector<int> temp;
    int curr_sum = root->val;
    temp.push_back(root->val);
    if(curr_sum == target) res.push_back(temp);
    for(int i=parents.size()-1; i>=0; i--){
        curr_sum += parents[i];
        temp.push_back(parents[i]);
        if(curr_sum == target) res.push_back(temp);
    }
    parents.push_back(root->val);
    search(root->left, target, parents, res);
    search(root->right, target, parents, res);
    parents.pop_back();
}

vector<vector<int> > getSumTarget(TreeNode* root, int target){
    vector<vector<int> > res;
    if(!root) return res;
    vector<int> parents;
    search(root, target, parents, res); 
    return res;
}

int main(){
    string arr[] = {"-1","5","#","4","#","#","2","-4","#"};
//    string arr[] = {"2","-1"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = create_tree(v);
    vector<vector<int> > res = getSumTarget(root, 6);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
