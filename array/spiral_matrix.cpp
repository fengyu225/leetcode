/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include "header.h"

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> res;
    int m = matrix.size();
    if(m == 0) return res;
    int n = matrix[0].size();
    int left = 0, right = n-1, low = 0, high = m-1;
    while(left<=right && low<=high){
        if(left<=right){
            for(int i=left; i<=right; i++) res.push_back(matrix[low][i]);
            low++;
        }
        if(low>high) break;
        if(low <= high){
            for(int i=low; i<=high; i++) res.push_back(matrix[i][right]);
            right--;
        }
        if(right<left) break;
        if(right >= left){
            for(int i=right; i>=left; i--) res.push_back(matrix[high][i]);
            high--;
        }
        if(high<low) break;
        if(low<=high){
            for(int i=high; i>=low; i--) res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}

int main(){
    vector<vector<int> > matrix = {
        {1, 2, 3}
    };

//    vector<vector<int> > matrix = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9},
//        {10, 11, 12}
//    };

    vector<int> res = spiralOrder(matrix);
    print_vector<int>(res);
    return 0;
}
