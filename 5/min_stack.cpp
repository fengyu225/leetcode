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
            s.push(x);
            if(min_s.empty()) min_s.push(x);
            else min_s.push(min(min_s.top(), x));
        }
        void pop() {
            if(s.empty()) return;
            s.pop();
            min_s.pop();
        }
        int top() {
            return s.top();        
        }
        int getMin() {
            return min_s.top();        
        }
    private:
        stack<int> s;
        stack<int> min_s;
};

int main(){
    MinStack s();
    return 0;
}