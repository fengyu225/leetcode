#include "lib.h"
#include <string>
#include <queue>

using namespace std;

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
    }
    return result;
}

TreeNode* create_tree(string v){
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