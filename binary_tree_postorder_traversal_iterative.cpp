#include<stdlib.h>
#include<stdio.h>
#include<stack>

using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};


void post_order(struct node* root){
    stack<struct node*> s;
    stack<struct node*> s_t;
    s.push(root);
    while(!s.empty()){
        struct node* t = s.top();
        s_t.push(t);
        s.pop();
        if(t->left){
            s.push(t->left);
            continue;
        }
        if(t->right){
            s.push(t->right);
            continue;
        }
    }
    while(!s_t.empty()){
        printf("%d ", s_t.top()->val);
        s_t.pop();
    }
    printf("\n");
}


int main(){
    struct node one={.val=1,.left=NULL,.right=NULL};
    struct node two={.val=2,.left=NULL,.right=NULL};
    struct node three={.val=3,.left=NULL,.right=NULL};
    one.right=&two;
    two.left=&three;
    post_order(&one);
    return 0;
}
