/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its vertical order traversal as:

[
  [9],
  [3,15],
  [20],
  [7]
]

Given binary tree [3,9,20,4,5,2,7],

    _3_
   /   \
  9    20
 / \   / \
4   5 2   7

return its vertical order traversal as:

[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
*/

#include "header.h"

void add_node_to_map(unordered_map<int, vector<int> >& m, pair<int, TreeNode*>& p){
    if(m.find(p.first) == m.end()) m[p.first] = vector<int>();
    m[p.first].push_back(p.second->val);
}

vector<vector<int> > verticalOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root) return res;
    unordered_map<int, vector<int> > m;
    queue<pair<int, TreeNode*> > q;
    q.push(make_pair(0, root));
    int l_max = INT_MAX, r_max = INT_MIN;
    while(!q.empty()){
        pair<int, TreeNode*> curr = q.front();
        m[curr.first].push_back(curr.second->val);
        l_max = min(l_max, curr.first);
        r_max = max(r_max, curr.first);
        q.pop();
        if(curr.second->left) q.push(make_pair(curr.first-1, curr.second->left));
        if(curr.second->right) q.push(make_pair(curr.first+1, curr.second->right));
    }
    for(int i=l_max; i<=r_max; i++)
        if(m.find(i) != m.end()) res.push_back(m[i]);
    return res;
}

int main(){
    //vector<string> tr = {"3", "9", "20", "4", "5", "2", "7"};
    vector<string> tr = {"1", "#", "3"};
    TreeNode* root = create_tree(tr);
    vector<vector<int> > res = verticalOrder(root);
    for(auto m:res) print_vector<int>(m);
    return 0;
}