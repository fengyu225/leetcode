/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include "header.h"

class MinStack {
public:
    void push(int x) {
        if(st.empty() || x<=st.top()) st.push(x);     
        st1.push(x);
    }

    void pop() {
        if(st.top() == st1.top()) st.pop();
        st1.pop();
    }

    int top() {
        return st1.top(); 
    }

    int getMin() {
        return st.top();    
    }
private:
    stack<int> st;
    stack<int> st1;
};

int main(){
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-1);
    cout<<s.getMin()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    return 0;
}