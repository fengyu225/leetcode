/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

*/

#include "header.h"

bool comp(vector<int>& a, vector<int>& b){
    // return true if a<=b
    int a_sz = a.size(), b_sz = b.size();
    if(a_sz<b_sz) return true;
    if(a_sz>b_sz) return false;
    for(int i=0; i<a_sz; i++){
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false; 
    }
    return true;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1_sz = nums1.size(), n2_sz = nums2.size();
    vector<vector<vector<vector<int> > > > arr(n1_sz+1, vector<vector<vector<int> > >(n2_sz+1, vector<vector<int> >(k+1, vector<int>())));
    for(int i=1; i<=n1_sz; i++){
        for(int m=1; m<=min(k,i); m++){
            vector<int> res;
            vector<int> temp = arr[i-1][0][m-1];
            temp.push_back(nums1[i-1]);
            if(comp(arr[i-1][0][m], temp)) res = temp;
            else res = arr[i-1][0][m];
            arr[i][0][m] = res; 
        }
    }
    for(int i=1; i<=n2_sz; i++){
        for(int m=1; m<=min(k,i); m++){
            vector<int> res;
            vector<int> temp = arr[0][i-1][m-1];
            temp.push_back(nums2[i-1]);
            if(comp(arr[0][i-1][m],temp)) res = temp;
            else res = arr[0][i-1][m];
            arr[0][i][m] = res; 
        }
    }
    for(int i=1; i<=n1_sz; i++){
        for(int j=1; j<=n2_sz; j++){
            for(int m=1; m<=k; m++){
                if(i+j<m) continue;
                vector<int> x = (i>=1&&j>=1)?arr[i-1][j-1][m]:vector<int>();
                vector<int> y;
                if(comp(arr[i-1][j][m-1], arr[i][j-1][m-1])){
                    y=arr[i][j-1][m-1];
                    y.push_back(nums2[j-1]);
                }
                else if(comp(arr[i][j-1][m-1], arr[i-1][j][m-1])){
                    y = arr[i-1][j][m-1];
                    y.push_back(nums1[i-1]);
                }
                if(comp(x,y)) arr[i][j][m] = y;
                else arr[i][j][m] = x;
            }
        }
    }
    return arr[n1_sz][n2_sz][k];
}

int main(){
    //vector<int> nums1 = {3, 4, 6, 5};
    //vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    //vector<int> res = maxNumber(nums1, nums2, 5);
    vector<int> nums1 = {1,5,8,1,4,0,8,5,0,7,0,5,7,6,0,5,5,2,4,3,6,4,6,6,3,8,1,1,3,1,3,5,4,3,9,5,0,3,8,1,4,9,8,8,3,4,6,2,5,4,1,1,4,6,5,2,3,6,3,5,4,3,0,7,2,5,1,5,3,3,8,2,2,7,6,7,5,9,1,2};
    vector<int> nums2 = {7,8,5,8,0,1,1,6,1,7,6,9,6,6,0,8,5,8,6,3,4,0,4,6,7,8,7,7,7,5,7,2,5,2,1,9,5,9,3,7,3,9,9,3,1,4,3,3,9,7,1,4,4,1,4,0,2,3,1,3,2,0,2,4,0,9,2,0,1,3,9,1,2,2,6,6,9,3,6,0};
    vector<int> res = maxNumber(nums1, nums2, 80);
    print_vector<int>(res);
    return 0;
}