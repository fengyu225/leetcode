/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

#include "header.h"

bool verifyPreorder(vector<int>& preorder) {
    int sz = preorder.size();
    stack<int> st;
    int curr_p = INT_MIN;
    for(int i=0; i<sz; i++){
        if(st.empty() || st.top()>preorder[i]){
            if(preorder[i]<curr_p) return false;
            st.push(preorder[i]);
        }
        else{
            while(!st.empty() && st.top()<preorder[i]){
                curr_p = st.top();
                st.pop();
            }
            st.push(preorder[i]);
        }
    }
    return true;
}

int main(){
    vector<int> preorder = {6, 3, 1, 5, 4, 7, 9, 8};
    cout<<verifyPreorder(preorder)<<endl;
    return 0;
}