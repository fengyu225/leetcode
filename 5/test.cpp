/*
use two queues, one is for current level and the other is for next level
as it poping current level, push node to next level
after current level is empty, the switch two queues
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef struct tnode {
  int value;
  struct tnode* left;
  struct tnode* right;
} Node;

void printTree (Node* root) {
    if(!root) return;
    queue<Node*> q[2];
    queue<Node*> curr;
    queue<Node*> next;
    curr.push(root);
    q[0] = curr;
    q[1] = next;
    int x = 0; //x is used to switch between two queues
    while(!q[x%2].empty()){
        Node* curr_n=q[x%2].front();
        int sz = q[x%2].size();
        cout<<curr_n->value;
        if(sz>1) cout<<",";
        q[x%2].pop();
        if(curr_n->left)
            q[(x+1)%2].push(curr_n->left); //push left child
        if(curr_n->right)
            q[(x+1)%2].push(curr_n->right); //push right child
        if(q[x%2].empty()){
            x++;
            cout<<endl;
        }
    }
}

// run time complexity is O(n) where n is the number of nodes in the input tree

int main(){
    vector<Node*> arr;
    for(int i=0; i<7; i++){
        Node* n = new Node();
        arr.push_back(n);
    }
    arr[0]->value = 5;
    arr[0]->left = arr[1];
    arr[0]->right = arr[2];
    arr[1]->value = 3;
    arr[1]->left = arr[3];
    arr[2]->value = 1;
    arr[2]->left = arr[4];
    arr[2]->right = arr[5];
    arr[3]->value = 9;
    arr[4]->value = 4;
    arr[4]->left = arr[6];
    arr[5]->value = 5;
    arr[6]->value = 2;
    printTree(arr[0]);
    return 0;
}
//int main(){
//    Node* n0 = new Node();
//    Node* n1 = new Node();
//    Node* n2 = new Node();
//    Node* n3 = new Node();
//    Node* n4 = new Node();
//    n0->value = 0;
//    n1->value = 1;
//    n2->value = 2;
//    n3->value = 3;
//    n4->value = 4;
//    n0->left = n1;
//    n0->right = n2;
//    n2->left=n3;
//    n2->right = n4;
//    printTree(n0);
//    return 0;
//}