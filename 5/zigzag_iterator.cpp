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
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        num_vec = 2;
        arr.push_back(&v1);
        arr.push_back(&v2);
        curr_idx.push_back(0);
        curr_idx.push_back(0);
        total_sz = v1.size()+v2.size();
        curr_pos = 0;
    }

    int next() {
        while(curr_idx[curr%num_vec]>=arr[curr%num_vec]->size()) curr++;
        int res = (*arr[curr%num_vec])[curr_idx[curr%num_vec]];
        curr_idx[curr%num_vec]++;
        curr++;
        curr_pos++;
        return res;
    }

    bool hasNext() {
        return curr_pos<total_sz; 
    }
private:
    int total_sz;
    int curr_pos;
    int curr;
    vector<vector<int>* > arr;
    vector<int> curr_idx;
    int num_vec;
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