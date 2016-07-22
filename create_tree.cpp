#include "header.h"

TreeNode* create_tree(string& v){
    if(v[0] == '#') return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(v[0]-'0');
    TreeNode* curr_n = root;
    q.push(curr_n);
    int curr = 1;
    while(!q.empty() && curr_n){
        TreeNode* l = curr<v.length() && v[curr] != '#'?new TreeNode(v[curr]-'0'):NULL;
        TreeNode* r = curr+1<v.length() && v[curr+1] != '#'?new TreeNode(v[curr+1]-'0'):NULL;
        q.push(l);
        q.push(r);
        curr_n->left = l;
        curr_n->right = r;
        q.pop();
        curr += 2;
        curr_n = l?l:r; 
    }
    return root;
}

void inorder(TreeNode* curr){
    if(!curr) return;
    cout<<curr->val<<" ";
    inorder(curr->left);
    inorder(curr->right);
}

int main(){
    string s("1#23");
    TreeNode* t = create_tree(s);
    inorder(t);
    cout<<endl;
    return 0;
}