/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

#include "header.h"

//bool verify(vector<int>& preorder, int l, int r){
//    if(l == r) return true;
//    int x = preorder[l];
//    int i = l+1;
//    while(i<=r && preorder[i]<x) i++;
//    int j = i;
//    while(j<=r) if(preorder[j++]<x) return false;
//    bool l_res = i==l+1?true:verify(preorder,l+1,i-1);
//    bool r_res = i==r+1?true:verify(preorder,i,r);
//    return l_res && r_res;
//}
//
//bool verifyPreorder(vector<int>& preorder){
//    int sz = preorder.size();
//    if(sz == 1) return true;
//    int l = 0, r=sz-1;
//    return verify(preorder, l, r);
//}

bool verifyPreorder(vector<int>& preorder){
    int sz = preorder.size();
    if(sz < 2) return true;
    stack<int> s;
    s.push(preorder[0]);
    int curr = INT_MIN;
    for(int i=1; i<sz; i++){
        if(s.empty() || preorder[i]<s.top()){
            if(curr!=INT_MIN && preorder[i]<curr) return false;
            s.push(preorder[i]);
        }
        else{
            while(!s.empty() && s.top()<preorder[i]){
                curr = s.top();
                s.pop();
            }
            if(s.empty()) s.push(preorder[i]);
            else if(preorder[i]<curr) return false;
        }
    }
    return true;
}

int main(){
//    vector<int> preorder={6, 3, 1, 2, 5, 4, 7};
    //vector<int> preorder={6, 3, 1, 21, 5, 4, 7};
    vector<int> preorder={2,1};
    cout<<verifyPreorder(preorder)<<endl;
    return 0;
}