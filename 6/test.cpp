#include "header.h"

int main(){
    cout<<"hello"<<endl;
    priority_queue<int,vector<int> > q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.top()<<endl;
    return 0;
}