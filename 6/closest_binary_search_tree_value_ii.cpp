/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

#include "header.h"

int get_next_pred(stack<TreeNode*>& pred){
    int res = pred.top()->val;
    TreeNode* x = pred.top()->left;
    pred.pop();
    while(x){
        pred.push(x);
        x = x->right;
    }
    return res;
}

int get_next_succ(stack<TreeNode*>& succ){
    int res = succ.top()->val;
    TreeNode* x = succ.top()->right;
    succ.pop();
    while(x){
        succ.push(x);
        x = x->left;
    }
    return res;
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> res;
    TreeNode* curr = root;
    stack<TreeNode*> pred;
    while(curr){
        if(curr->val == target){
            pred.push(curr);
            break;
        }
        else if(curr->val < target){
            pred.push(curr);
            if(!curr->right) break;
            curr = curr->right;
        }
        else{
            if(!curr->left) break;
            curr = curr->left;
        }
    }
    stack<TreeNode*> succ;
    curr = root;
    while(curr){
        if(curr->val == target){
            succ.push(curr);
            break;
        }
        else if(curr->val>target){
            succ.push(curr);
            if(!curr->left) break;
            curr = curr->left;
        }
        else{
            if(!curr->right) break;
            curr = curr->right;
        }
    }
    int found = 0;
    if(!succ.empty() && !pred.empty() && succ.top()->val == pred.top()->val) get_next_pred(pred);
    while(found<k){
        if(succ.empty()) res.push_back(get_next_pred(pred));
        else if(pred.empty()) res.push_back(get_next_succ(succ));
        else{
            double succ_diff = abs((double)succ.top()->val - target);
            double pred_diff = abs((double)pred.top()->val - target);
            if(succ_diff>pred_diff) res.push_back(get_next_pred(pred));
            else res.push_back(get_next_succ(succ));
        }
        found++;
    }
    return res;
}

int main(){
    //vector<string> v = {"5","3","10","1","4","7","11","#","#","#","#","6","#","#","12"};
    //TreeNode* root = create_tree(v);
    TreeNode* root = create_tree("1");
    vector<int> res = closestKValues(root, 0.0, 1);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}