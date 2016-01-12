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
    int curr_r, curr_c, sz;
    bool move_next;
    vector<vector<int> > v;
public:
    Vector2D(vector<vector<int> >& vec2d) {
        this->v = vec2d;
        move_next = true;
        curr_r = 0;
        curr_c = -1;
        sz = vec2d.size();
    }

    int next() {
        int res = v[curr_r][curr_c];
        move_next = true;
        return res;
    }

    bool hasNext() {
        if(!move_next) return true; //move_next is false iff (curr_r,curr_c) is valid & hasn't been used yet
        if(sz == curr_r) return false;
        curr_c++;
        while(curr_r<sz){
            if(curr_c == v[curr_r].size()){
                curr_r++;
                curr_c = 0;
            }
            else{
                move_next = false;
                return true;
            }
        }
        return false;
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