/*
Given a tree string expression in balanced parenthesis format:
(A(B(C)(D))(E)(F))

               A
             / | \
            B  E  F
           / \
          C   D

Return the corresponding tree (ie the root node).
*/

#include "header.h"

class StackNode{
    public:
        int type;
        char c;
        MultiTreeNode* t;
        StackNode(int type):type(type){}
};

MultiTreeNode* exp2Tree(string exp){
    stack<StackNode> s;
    for(char c:exp){
        if(c == '(' || c<='Z' && c>='A'){
            StackNode n(0);
            n.c = c;
            s.push(n);
        }
        else{
            stack<MultiTreeNode*> ss;
            while(!s.empty() && s.top().type == 1){
                ss.push(s.top().t);
                s.pop();
            }
            MultiTreeNode* t = new MultiTreeNode(s.top().c);
            s.pop();
            while(!ss.empty()){
                t->children.push_back(ss.top());
                ss.pop();
            }
            s.pop();
            StackNode s_n(1);
            s_n.t = t;
            s.push(s_n);
        }
    }
    return s.top().t;
}

void pre_order(MultiTreeNode* root){
    if(!root) return;
    cout<<root->c<<" ";
    for(MultiTreeNode* c:root->children) pre_order(c);
}

int main(){
    MultiTreeNode* res = exp2Tree("(A(B(C)(D))(E)(F))");
    pre_order(res);
    cout<<endl;
    return 0;
}