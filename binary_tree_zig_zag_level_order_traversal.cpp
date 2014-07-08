#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

}

int main(){
    TreeNode n0(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(7);
    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    vector<vector<int> > res = zigzagLevelOrder(&n0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
