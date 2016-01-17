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
            cout<<curr->val<<"->"<<x->val<<endl;
            curr->next = x;
            curr = curr->next;
        }
    }
    cout<<"======================"<<endl;
    return result;
}

ListNode* create_list(vector<int> arr){
    cout<<"======================"<<endl;
    ListNode* result = NULL;
    ListNode* curr = NULL;
    int n = (int)arr.size();
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            cout<<curr->val<<"->"<<x->val<<endl;
            curr->next = x;
            curr = curr->next;
        }
    }
    cout<<"======================"<<endl;
    return result;
}

ListNode* create_list(int arr[], int n, int s){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    ListNode* end = NULL;
    ListNode* start = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(arr[i] == s) start=x;
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
        if(i==n-1) end=curr;
    }
    end->next = start;
    return result;
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

void in_order(TreeNode* root){
    if(!root) return;
    pre_order(root->left);
    printf("%d ", root->val);
    pre_order(root->right);
}

void print_random_list(RandomListNode* root){
    while(root){
        string x = "";
        if(root->random)
            x += to_string(root->random->label);
        else
            x += "NULL";
        cout<<root->label<<"("<<x<<") ";
        root = root->next;
    }
    printf("\n");
}

void print_list(ListNode* curr){
    if(!curr) return;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


void print_arr(vector<int>& nums, int l, int r){
    for(int i = l; i<=r; i++) cout<<nums[i]<<" ";
    cout<<endl;
}