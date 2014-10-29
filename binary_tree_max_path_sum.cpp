#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_max(vector<int>& vec){
    if(vec.size() == 0) return INT_MIN;
    int res = vec[0];
    for(int i=1; i<vec.size(); i++)
        res = std::max(vec[i], res);
    return res;
}

void max_path_sum(TreeNode* root, int& path_max, int& longest){
    if(!root){
        longest = 0;
        return;
    }
    int l_max = INT_MIN;
    int r_max = INT_MIN;
    int ll,rl;
    max_path_sum(root->left,l_max,ll);
    max_path_sum(root->right,r_max,rl);
    longest = std::max(root->val,std::max(ll,rl)+root->val);
    vector<int> temp;
    temp.push_back(l_max);
    temp.push_back(r_max);
    temp.push_back(std::max(root->val,ll+root->val));
    temp.push_back(std::max(root->val,rl+root->val));
    temp.push_back(ll+rl+root->val);
    path_max = get_max(temp);
}

int maxPathSum(TreeNode* t1){
    if(!t1) return INT_MIN;
    int path_max = INT_MIN; 
    int longest = INT_MIN;
    max_path_sum(t1,path_max,longest);
    return path_max;
}
int main(){
//    TreeNode t1(1);
//    TreeNode t2(-2);
//    TreeNode t3(3);
//    t1.left = &t2;
//    t1.right = &t3;
    TreeNode t1(-1);
    TreeNode t2(5);
    TreeNode t3(4);
    TreeNode t4(2);
    TreeNode t5(-4);
    t1.left = &t2;
    t2.left = &t3;
    t3.right = &t4;
    t4.left = &t5;
    printf("%d\n", maxPathSum(&t1));
    return 0;
}
