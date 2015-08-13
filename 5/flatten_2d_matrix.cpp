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
    Vector2D(vector<vector<int> >& vec2d) {
        curr_r = 0;
        row = vec2d.size();
        curr_c = -1;
        this->vec2d = vec2d;
        next_r = next_c = 0;
    }

    int next() {
        curr_r = next_r;
        curr_c = next_c;
        return this->vec2d[curr_r][curr_c];
    }

    bool hasNext() {
        if(row == 0) return false;
        int old_r = curr_r, old_c = curr_c;
        curr_c++;
        if(curr_c == vec2d[curr_r].size()){
            do{
                curr_r++;
                curr_c=0;
            }while(curr_r<row && vec2d[curr_r].size() == 0);
            if(curr_r == row) return false;
        }
        next_c = curr_c;
        next_r = curr_r;
        curr_c = old_c;
        curr_r = old_r;
        return true;
    }
private:
    int row;
    int curr_r;
    int curr_c;
    int next_r;
    int next_c;
    vector<vector<int> > vec2d;
};

int main(){
//    int arr0[] = {1, 2};
//    int arr1[] = {3};
//    int arr2[] = {4,5,6};
//    vector<int> v_arr0(arr0, arr0+sizeof(arr0)/sizeof(arr0[0]));
//    vector<int> v_arr1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
//    vector<int> v_arr2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
//    vector<vector<int> > vec2d = {v_arr0, v_arr1, v_arr2};
//
    int arr0[] = {1};
    int arr1[] = {};
    vector<int> v_arr0(arr0, arr0+sizeof(arr0)/sizeof(arr0[0]));
    vector<int> v_arr1(arr1, arr1);
    vector<vector<int> > vec2d = {v_arr0, v_arr1};

    Vector2D vec(vec2d);
    while(vec.hasNext()){
        cout<<vec.next()<<endl;    
    }
    cout<<endl;
    return 0;
}