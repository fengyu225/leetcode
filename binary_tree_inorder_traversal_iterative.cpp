#include<stdlib.h>
#include<stdio.h>
#include<stack>

using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};


void in_order(struct node* root){
    stack<struct node*> s;
    s.push(root);
    while(!s.empty()){
        struct node* t = s.top();
        if(t->left){
            s.push(t->left);
            continue;
        }
        printf("%d ", t->val);
        while(!s.empty() && !s.top()->right){
            printf("%d ", s.top()->val);
            s.pop();
        }
        if(s.top()->right){
            printf("%d ", s.top()->val);
            t=s.top()->right;
            s.pop();
            s.push(t);
        }
    }
    printf("\n");
}


int main(){
    struct node one={.val=1,.left=NULL,.right=NULL};
    struct node two={.val=2,.left=NULL,.right=NULL};
    struct node three={.val=3,.left=NULL,.right=NULL};
    one.right=&two;
    two.left=&three;
    in_order(&one);
    return 0;
}
