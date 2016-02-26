/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

#include "header.h"

void initA(vector<vector<int> >& A, unordered_map<int,vector<pair<int,int> > >& a_m){
    int r = A.size(), c = A[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            if(A[i][j] != 0) a_m[i].push_back(make_pair(j, A[i][j]));
    } 
}   

void initB(vector<vector<int> >& B, unordered_map<int,vector<pair<int,int> > >& b_m){
    int r = B.size(), c = B[0].size();
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++)
            if(B[j][i] != 0) b_m[i].push_back(make_pair(j, B[j][i]));
    }
}

vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
    if(A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0)
        return vector<vector<int> >();
    unordered_map<int, vector<pair<int,int> > > a_m, b_m;
    int a_r = A.size(), a_c = A[0].size(), b_r = B.size(), b_c = B[0].size();
    vector<vector<int> > res(a_r, vector<int>(b_c, 0));
    initA(A, a_m);
    initB(B, b_m);
    for(auto i:a_m){
        for(auto j:b_m){
            int temp = 0;
            for(int l = 0, r = 0; l<i.second.size() && r<j.second.size(); ){
                if(i.second[l].first == j.second[r].first){
                    temp += i.second[l].second*j.second[r].second;
                    l++;
                    r++;
                }
                else if(i.second[l].first<j.second[r].first) l++;
                else r++;
            }
            res[i.first][j.first] = temp;
        }
    } 
    return res;
}

int main(){
    vector<vector<int> > A = {
        {1, 0, 0},
        {-1, 0, 3}
    };
    vector<vector<int> > B = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    vector<vector<int> > res = multiply(A, B);
    for(auto v : res) print_vector<int>(v);
    return 0;
}