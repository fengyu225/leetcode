#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int> >& result){
    if(!root)
        return;
//    printf("node: %d, sum=%d\n", root->val,sum);
    if(!root->left && !root->right){
        if(root->val == sum){
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
        }
        return;
    }
    path.push_back(root->val);
    if(root->left)
        dfs(root->left, sum-root->val, path, result);
    if(root->right)
        dfs(root->right, sum-root->val, path, result);
    path.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum){
    vector<vector<int> > result;
    vector<int> path;
    dfs(root,sum,path,result);
    return result;
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(1);
    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    vector<vector<int> > r = pathSum(&n1, 7);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
