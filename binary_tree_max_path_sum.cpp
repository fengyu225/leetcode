#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find_max(int a, int b, int c){
    if(a>b){
        if(c>a) return c;
        else return a;
    }
    else{
        if(c>b) return c;
        else return b;
    }
}

void max_sum(TreeNode* curr, int& path_max,  int& left_max, int& right_max){
    if(!curr->left && !curr->right){
        left_max = right_max = 0;
        path_max = curr->val;
        return ;
    }
    int left_path_max = INT_MIN;
    int left_left_max = INT_MIN;
    int left_right_max = INT_MIN;
    if(curr->left){
        max_sum(curr->left,left_path_max,left_left_max,left_right_max);
        left_max = left_left_max>left_right_max?left_left_max:left_right_max;
        left_max = left_max>0?curr->left->val+left_max:curr->left->val;
    }
    int right_path_max = INT_MIN;
    int right_left_max = INT_MIN;
    int right_right_max = INT_MIN;
    if(curr->right){
        max_sum(curr->right,right_path_max,right_left_max,right_right_max);
        right_max = right_left_max>right_right_max?right_left_max:right_right_max;
        right_max = right_max>0?curr->right->val+right_max:curr->right->val;
    }
    path_max = left_path_max>right_path_max?left_path_max:right_path_max;
    int t = INT_MIN;
    if(left_max != INT_MIN)
        t = left_max;
    if(right_max != INT_MIN)
        t = t==INT_MIN?right_max:find_max(t,right_max,t+right_max);
    int c = curr->val;
    if(t != INT_MIN)
        t = c>c+t?c:c+t;
    else
        t = c;
    path_max = t>path_max?t:path_max;
}

int maxPathSum(TreeNode* t1){
    int path_max = INT_MIN;
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    max_sum(t1,path_max,left_max,right_max);
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
