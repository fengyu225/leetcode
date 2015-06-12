/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include "header.h"

int longestConsecutive(vector<int>& nums){
    unordered_map<int,int> m;
    int res = 1;
    for(int i=0; i<nums.size(); i++){
        if(m.find(nums[i]) != m.end()) continue;
        int x = 1, l=0, r=0;
        bool left = false, right=false;
        m[nums[i]] = 1;
        if(m.find(nums[i]-1) != m.end()){
            l = m[nums[i]-1];
            x += abs(l);
            m[nums[i]] = -1*(1+abs(l));
            m[nums[i]-abs(l)] = x;
            left = true;
        }
        if(m.find(nums[i]+1) != m.end()){
            r = m[nums[i]+1];
            x += abs(r);
            m[nums[i]] = x;
            m[nums[i]+abs(r)] = -1*x;
            right = true;
        }
        res = max(res,x);
        if(left && right){
            m[nums[i]-abs(l)] = x;
            m[nums[i]+abs(r)] = -1*x;
        }
    }
    return res;
}

//int longestConsecutive(vector<int>& nums){
//    unordered_map<int,int> m;
//    int res = 1;
//    for(int i=0; i<nums.size(); i++) m[nums[i]] = 1;
//    for(int i=0; i<nums.size(); i++){
//        if(m[nums[i]] == 0) continue;
//        int x = 1, j=nums[i]-1;
//        while(m.find(j)!=m.end()){
//            m[j] = 0;
//            j--;
//            x++;
//        }
//        j=nums[i]+1;
//        while(m.find(j)!=m.end()){
//            m[j]=0;
//            j++;
//            x++;
//        }
//        res = max(res,x);
//    }
//    return res;
//}

int main(){
    int arr[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    printf("%d\n", longestConsecutive(num));
    return 0;
}
