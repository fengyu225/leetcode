/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

#include "header.h"

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        
    }

    int next() {
        
    }

    bool hasNext() {
        
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
//    vector<vector<int> > vec2d = {
//        {1, 2};
//        {3};
//        {4,5,6};
//    };
    vector<vector<int> > vec2d = {
        {1},
        {}
    };
    Vector2D vec(vec2d);
    while(vec.hasNext()){
        cout<<vec.next()<<endl;    
    }
    cout<<endl;
    return 0;
}