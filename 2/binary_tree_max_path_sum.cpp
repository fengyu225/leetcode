#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_max(vector<int>& v){
    int res = v[0];
    for(auto e : v)
        res = std::max(res,e);
    return res;
}

int max_sum(TreeNode* curr, int& max){
    if(!curr)
        return 0;
    int l_max = INT_MIN;
    int l = max_sum(curr->left,l_max);
    int r_max = INT_MIN;
    int r = max_sum(curr->right,r_max);
    int m = std::max(l_max,r_max);
    int p = std::max(l,r);
    if(p>0)
        p = p+curr->val;
    else
        p = curr->val;
    vector<int> v = {l_max,r_max,curr->val,curr->val+l,curr->val+r,curr->val+l+r};
    max = get_max(v);
    return p;
}

int maxPathSum(TreeNode* t1){
    int max = 0;
    max_sum(t1,max);
    return max;
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
