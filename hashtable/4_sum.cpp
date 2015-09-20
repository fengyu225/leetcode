/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include "header.h"

/* hashtable */
vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > res;
    int sz = nums.size();
    unordered_map<int,vector<pair<int,int> > > m;
    sort(nums.begin(), nums.end());
    for(int i=sz-1; i>0; i--){
        if(i<sz-1 && nums[i] == nums[i+1]) continue;
        for(int j=i-1; j>=0; j--){
            if(j<i-1 && nums[j] == nums[j+1]) continue;
            if(m.find(nums[i]+nums[j]) == m.end()) m[nums[i]+nums[j]] = vector<pair<int,int> >();
            m[nums[i]+nums[j]].push_back(make_pair(j, i));
        }
    }
    for(int i=0; i<sz; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<sz; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int t = target-nums[i]-nums[j];
            if(m.find(t) != m.end()){
                for(auto p:m[t])
                    if(p.first>j)
                        res.push_back(vector<int>({nums[i], nums[j], nums[p.first], nums[p.second]}));
            }
        }
    }
    return res;
}
    
///* hashtable */
//vector<vector<int> > fourSum(vector<int>& nums, int target) {
//    int sz = nums.size();
//    vector<vector<int> > res;
//    if(sz<4) return res;;
//    for(int i=0; i+3<sz; i++){
//        if(i>0 && nums[i] == nums[i-1]) continue;
//        for(int j=i+1; j+2<sz; j++){
//            if(j>i+1 && nums[j] == nums[j-1]) continue;
//            unordered_set<int> m;
//            for(int k = j+1; k<sz; k++){
//                if(m.find(nums[k]) != m.end()) continue;
//                int temp = target-nums[i]-nums[j];
//                if(m.find(temp-nums[k]) != m.end()){
//                    vector<int> temp_v;
//                    temp_v.push_back(nums[i]);
//                    temp_v.push_back(nums[j]);
//                    temp_v.push_back(nums[k]);
//                    temp_v.push_back(temp-nums[k]);
//                    res.push_back(temp_v);
//                }
//                m.insert(nums[k]);
//            }
//        }
//    }
//    return res;
//}

/* 2 pointers */
//vector<vector<int> > fourSum(vector<int>& nums, int target) {
//    int sz = nums.size();
//    vector<vector<int> > res;
//    if(sz<4) return res;
//    sort(nums.begin(), nums.end());
//    for(int i=0; i+3<sz; i++){
//        if(i>0 && nums[i] == nums[i-1]) continue;
//        for(int j = i+1; j+2<sz; j++){
//            if(j>i+1 && nums[j] == nums[j-1]) continue;
//            int k = j+1, l = sz-1;
//            while(k<l){
//                int temp_val = nums[i]+nums[j]+nums[k]+nums[l];
//                if(temp_val == target){
//                    vector<int> temp;
//                    temp.push_back(nums[i]);
//                    temp.push_back(nums[j]);
//                    temp.push_back(nums[k]);
//                    temp.push_back(nums[l]);
//                    res.push_back(temp);
//                    k++;
//                    l--;
//                    while(k<l && nums[k] == nums[k-1]) k++;
//                    while(k<l && nums[l] == nums[l+1]) l--;
//                }
//                else if(temp_val<target){
//                    k++;
//                    while(k<l && nums[k] == nums[k-1]) k++;
//                }
//                else{
//                    l--;
//                    while(k<l && nums[l] == nums[l+1]) l--;
//                }
//            }
//        }
//    }
//    return res;
//}

//[-489,-475,-469,-468,-467,-462,-456,-443,-439,-425,-425,-410,-401,-342,-341,-331,-323,-307,-299,-262,-254,-245,-244,-238,-229,-227,-225,-224,-221,-197,-173,-171,-160,-142,-142,-136,-134,-125,-114,-100,-86,-81,-66,-47,-37,-34,4,7,11,34,60,76,99,104,113,117,124,139,141,143,144,146,157,157,178,183,185,189,192,194,221,223,226,232,247,249,274,281,284,293,298,319,327,338,340,368,375,377,379,388,390,392,446,469,480,490], 2738

int main(){
    //int arr[] = {1, 0, -1, 0, -2, 2};
    //vector<int> num = {0, 0, 0, 0};
    vector<int> num = {1, 0, -1, 0, -2, 2};
//    vector<int> num = {-489,-475,-469,-468,-467,-462,-456,-443,-439,-425,-425,-410,-401,-342,-341,-331,-323,-307,-299,-262,-254,-245,-244,-238,-229,-227,-225,-224,-221,-197,-173,-171,-160,-142,-142,-136,-134,-125,-114,-100,-86,-81,-66,-47,-37,-34,4,7,11,34,60,76,99,104,113,117,124,139,141,143,144,146,157,157,178,183,185,189,192,194,221,223,226,232,247,249,274,281,284,293,298,319,327,338,340,368,375,377,379,388,390,392,446,469,480,490};
    //vector<vector<int> > res = fourSum(num,2378);
    vector<vector<int> > res = fourSum(num,0);
    print_2d_vector<int>(res);
    return 0;
}