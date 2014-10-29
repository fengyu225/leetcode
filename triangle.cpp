/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/

#include "header.h"

using namespace std;

int minimumTotal(vector<vector<int> >& triangle){
    int res = INT_MAX;
    if(triangle.size() == 0) return res;
    if(triangle.size() == 1) return triangle[0][0];
    int levels = triangle.size();
    vector<int> curr_level(triangle[levels-1].size(),0);
    vector<int> last_level(triangle[levels-1].size(),0);
    vector<int> level_arr[2] = {last_level,curr_level};
    level_arr[0][0] = triangle[0][0];
    for(int i=1;i<levels;i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j == 0)
                level_arr[i%2][j] = triangle[i][j]+level_arr[(i-1)%2][j];
            else if(j == triangle[i].size()-1)
                level_arr[i%2][j] = triangle[i][j]+level_arr[(i-1)%2][j-1];
            else
                level_arr[i%2][j] = triangle[i][j]+std::min(level_arr[(i-1)%2][j],level_arr[(i-1)%2][j-1]);
//            cout<<"i: "<<i<<" j: "<<j<<" level_arr: "<<level_arr[i%2][j]<<endl;
            if(i == levels-1)
                res = std::min(level_arr[i%2][j],res);
        }
    }
    return res;
}

int main(){
    int arr0[] =    {2};
    vector<int> s0(arr0,arr0+sizeof(arr0)/sizeof(int));
    int arr1[] =   {3, 4};
    vector<int> s1(arr1,arr1+sizeof(arr1)/sizeof(int));
    int arr2[] =  {6, 5, 7};
    vector<int> s2(arr2,arr2+sizeof(arr2)/sizeof(int));
    int arr3[] = {4, 1, 8, 3};
    vector<int> s3(arr3,arr3+sizeof(arr3)/sizeof(int));
    vector<vector<int> > triangle;
    triangle.push_back(s0);
    triangle.push_back(s1);
    triangle.push_back(s2);
    triangle.push_back(s3);
    printf("%d\n", minimumTotal(triangle));
    return 0;
}
