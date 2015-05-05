#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_sum(TreeNode* curr, int& max){
    if(!curr)
        return 0;
    int l = max_sum(curr->left,max);
    int r = max_sum(curr->right,max);
    int m = curr->val;
    if(l>0)
        m += l;
    if(r>0)
        m += r;
    max = max>m?max:m;
    int m_l_r = l>r?l:r;
    if(m_l_r>0)
        return curr->val+m_l_r;
    else
        return curr->val;
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
