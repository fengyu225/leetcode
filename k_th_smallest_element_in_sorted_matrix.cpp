/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note: 
You may assume k is always valid, 1 ≤ k ≤ n^2.
*/

#include "header.h"

typedef pair<int,pair<int,int> > q_node;

class comp{
    public:
        bool operator() (q_node& a, q_node& b){
            return a.first>b.first;
        }
};

int kthSmallest(vector<vector<int> >& matrix, int k) {
    int n = matrix.size();
    priority_queue<q_node, vector<q_node>, comp> pq;
    for(int i=0; i<n; i++) pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
    int res; 
    for(int i=1; i<=k; i++){
        q_node temp = pq.top();
        pq.pop();
        res = temp.first;
        int a = temp.second.first;
        int b = temp.second.second+1;
        if(b<n) pq.push(make_pair(matrix[a][b], make_pair(a, b)));
    }
    return res;
}

int main(){
//    vector<vector<int> > matrix = {
//        {3, 4, 5},
//        {3, 5, 5},
//        {6, 7, 8}
//    };
//    cout<<kthSmallest(matrix, 1)<<endl;
//    cout<<kthSmallest(matrix, 2)<<endl;
//    cout<<kthSmallest(matrix, 3)<<endl;
//    cout<<kthSmallest(matrix, 4)<<endl;
//    cout<<kthSmallest(matrix, 5)<<endl;
//    cout<<kthSmallest(matrix, 6)<<endl;
//    cout<<kthSmallest(matrix, 7)<<endl;
//    cout<<kthSmallest(matrix, 8)<<endl;
//    cout<<kthSmallest(matrix, 9)<<endl;
    vector<vector<int> > matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout<<kthSmallest(matrix, 7)<<endl;
    return 0;
}
