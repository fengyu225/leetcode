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

int get_pred(stack<TreeNode*>& pred){
    TreeNode* curr = pred.top();
    int res = curr->val;
    pred.pop();
    curr = curr->left;
    for(;curr;pred.push(curr), curr = curr->right);
    return res;
}

int get_succ(stack<TreeNode*>& succ){
    TreeNode* curr = succ.top();
    int res = curr->val;
    succ.pop();
    curr = curr->right;
    for(;curr;succ.push(curr), curr = curr->right);
    return res;
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> res;
    stack<TreeNode*> pred;
    stack<TreeNode*> succ;
    TreeNode* curr = root;
    while(curr){
        if(curr->val == target){
            pred.push(curr);
            break;
        }
        else if(curr->val<target){
            pred.push(curr);
            curr = curr->right;
        }
        else curr = curr->left;
    }
    curr = root;
    while(curr){
        if(curr->val == target){
            succ.push(curr);
            break;
        }
        else if(target>curr->val) curr = curr->right;
        else{
            succ.push(curr);
            curr = curr->left;
        }
    }
    if(!pred.empty() && !succ.empty() && pred.top()->val == succ.top()->val) get_pred(pred);    
    int count = 0;
    while(count<k){
        if(pred.empty()) res.push_back(get_succ(succ));
        else if(succ.empty()) res.push_back(get_pred(pred));
        else{
            double succ_diff = fabs((double)succ.top()->val - target);
            double pred_diff = fabs((double)pred.top()->val - target);
            if(succ_diff > pred_diff) res.push_back(get_pred(pred));
            else res.push_back(get_succ(succ));
        }
        count++;
    }
    return res;
}

int main(){
    vector<string> v = {"5","3","10","1","4","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
//    TreeNode* root = create_tree("1");
    vector<int> res = closestKValues(root, 11.6, 1);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}