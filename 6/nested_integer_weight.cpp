/*
Given an array [1, [2, [4] ] ] return 1*3+2*2+4*1=11
*/

#include "header.h"

class ArrayNode{
    public:
        int val;
        bool empty;
        vector<ArrayNode*> children;
        ArrayNode(int v):val(v),empty(false){}
        ArrayNode():empty(true){}
};

//int calc(ArrayNode* root, int& depth){
//    if(root->children.empty()){
//        depth = 1;
//        return root->empty?0:root->val;
//    }
//    int d = 1, res = 0;
//    for(ArrayNode* n : root->children) res += calc(n, d); 
//    depth = d+1;
//    res += depth*root->val;
//    return res;
//}
//
//int calc(ArrayNode* root){
//    if(!root || root->empty) return 0;
//    int depth = 1;
//    return calc(root, depth);
//}

int calc(ArrayNode* root){
    //BFS
    if(!root || root->empty) return 0;
    queue<ArrayNode*> qs[2];
    int curr = 0, curr_res = 0;
    qs[curr%2].push(root);
    stack<int> st;
    while(!qs[curr%2].empty()){
        ArrayNode* n = qs[curr%2].front();
        curr_res += n->empty?0:n->val;
        qs[curr%2].pop();
        for(ArrayNode* x : n->children) qs[(curr+1)%2].push(x);
        if(qs[curr%2].empty()){
            curr++;
            st.push(curr_res);
            curr_res = 0;
        }
    }
    int res = 0, l = 1;
    while(!st.empty()){
        res += st.top()*l;
        l++;
        st.pop();
    }
    return res;
}

int main(){
    ArrayNode* a = new ArrayNode(1);
    ArrayNode* b = new ArrayNode(2);
    ArrayNode* c = new ArrayNode(4);
    a->children.push_back(b);
    b->children.push_back(c);
    cout<<calc(a)<<endl;
    return 0;
}