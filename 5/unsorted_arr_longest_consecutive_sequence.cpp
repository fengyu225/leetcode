/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include "header.h"

int longestConsecutive(vector<int>& nums){

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
