/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

#include "header.h"

class ZigzagIterator {
    int k,curr,next_;
    bool check;
    vector<int> indexes;
    vector<vector<int> > vecs;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        k = 2;
        curr = -1;
        next_ = 0;
        check = true;
        indexes = vector<int>(k,0);
        vecs.push_back(v1);
        vecs.push_back(v2);
    }

    int next() {
        curr = next_;
        int res = vecs[curr][indexes[curr]];
        indexes[curr]++;
        check = true;
        return res;
    }

    bool hasNext() {
        if(!check) return true; 
        next_ = curr+1;
        for(int i=0; i<k; i++){
            next_ = next_%k;
            if(indexes[next_] == vecs[next_].size()){
                next_++;
            }
            else{
                check = false;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5, 6};
    ZigzagIterator i(v1, v2);
    while(i.hasNext()) cout<<i.next()<<endl;
    return 0;
}