#include "lib.h"
#include <string>
#include <queue>
#include <iostream>

using namespace std;

ListNode* create_list(int arr[], int n){
    cout<<"======================"<<endl;
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
    cout<<"======================"<<endl;
}

TreeNode* create_tree(string v){
    cout<<"======================"<<endl;
    if(v[0] == '#') return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(v[0]-'0');
    TreeNode* curr_n = root;
    q.push(curr_n);
    int curr = 1;
    while(!q.empty()){
        curr_n = q.front();
        TreeNode* l = curr<v.length() && v[curr] != '#'?new TreeNode(v[curr]-'0'):NULL;
        TreeNode* r = curr+1<v.length() && v[curr+1] != '#'?new TreeNode(v[curr+1]-'0'):NULL;
        cout<<curr<<" "<<curr_n->val<<" ";
        if(l) cout<<l->val<<" "; 
        else cout<<"NULL"<<" ";
        if(r) cout<<r->val<<" ";
        else cout<<"NULL"<<" ";
        cout<<endl;
        if(l) q.push(l);
        if(r) q.push(r);
        curr_n->left = l;
        curr_n->right = r;
        q.pop();
        curr += 2;
    }
    cout<<"======================"<<endl;
    return root;
}

TreeNode* create_tree(vector<string> v){
    if(v[0] == "#") return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(v[0]));
    TreeNode* curr_n = root;
    q.push(curr_n);
    int curr = 1;
    while(!q.empty()){
        curr_n = q.front();
        TreeNode* l = curr<v.size() && v[curr] != "#"?new TreeNode(stoi(v[curr])):NULL;
        TreeNode* r = curr+1<v.size() && v[curr+1] != "#"?new TreeNode(stoi(v[curr+1])):NULL;
        cout<<curr<<" "<<curr_n->val<<" ";
        if(l) cout<<l->val<<" "; 
        else cout<<"NULL"<<" ";
        if(r) cout<<r->val<<" ";
        else cout<<"NULL"<<" ";
        cout<<endl;
        if(l) q.push(l);
        if(r) q.push(r);
        curr_n->left = l;
        curr_n->right = r;
        q.pop();
        curr += 2;
    }
    return root;
}

TreeLinkNode* create_link_tree(vector<string> v){
    if(v[0] == "#") return NULL;
    queue<TreeLinkNode*> q;
    TreeLinkNode* root = new TreeLinkNode(stoi(v[0]));
    TreeLinkNode* curr_n = root;
    q.push(curr_n);
    int curr = 1;
    while(!q.empty()){
        curr_n = q.front();
        TreeLinkNode* l = curr<v.size() && v[curr] != "#"?new TreeLinkNode(stoi(v[curr])):NULL;
        TreeLinkNode* r = curr+1<v.size() && v[curr+1] != "#"?new TreeLinkNode(stoi(v[curr+1])):NULL;
        cout<<curr<<" "<<curr_n->val<<" ";
        if(l) cout<<l->val<<" "; 
        else cout<<"NULL"<<" ";
        if(r) cout<<r->val<<" ";
        else cout<<"NULL"<<" ";
        cout<<endl;
        if(l) q.push(l);
        if(r) q.push(r);
        curr_n->left = l;
        curr_n->right = r;
        q.pop();
        curr += 2;
    }
    return root;
}

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}

void print_random_list(RandomListNode* root){
    while(root){
        printf("%d ", root->label);
        root = root->next;
    }
    printf("\n");
}