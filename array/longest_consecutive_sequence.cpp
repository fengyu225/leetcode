/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include "header.h"

/*
We can use an unordered_map<int, pair<int,int> >, key is array's number and value is a pair with first int being the length of consecutive integers smaller than key, and with second int being the length of consecutive integers larger than key.

Let's walk through this example: [1, 3, 5, 2, 4]. We traverse the array:

1: before, map is {}; after, map is {1: (0,0)} //no integers seen so far that is smaller than 1, and no integers seen so far that is larger than 1

3: before, map is {1:(0,0)}; after, map is {1: (0,0), 3: (0,0) }

5: before, map is {1: (0,0), 3: (0,0) }; after, map is {1: (0,0), 3: (0,0), 5: (0,0) }

2: before, map is {1: (0,0), 3: (0,0), 5: (0,0) }; after, map is {1: (0,2), 3: (2,0), 5: (0,0), 2: (1,1) } // we first insert 2 and value is (1,0) because 1 is in map. Then we update 1's second value to 1. After than we update 2's second value to 1 because 3 is in map. Now 2's value is (1,1). Then we update 3's first value to 2, because 1 and 2 in map and update 1's second value to 2.

4: before, map is {1: (0,2), 3: (2,0), 5: (0,0), 2: (1,1) }; after, map is {1: (0,4), 3: (2,0), 5: (4,0), 2: (1,1), 4: (3,1) }

The following is code in c++:
*/

int longestConsecutive(vector<int>& nums) {
    int sz = nums.size();
    unordered_map<int,pair<int,int> > m;
    int res = 1;
    for(int i=0; i<sz; i++){
        if(m.find(nums[i]) != m.end()) continue;
        m[nums[i]] = make_pair(0, 0);
        if(m.find(nums[i]-1) != m.end()){
            m[nums[i]].first = m[nums[i]-1].first+1;
            m[nums[i]].second = max(0, m[nums[i]-1].second-1);
            if(m[nums[i]].first != 0)
                m[nums[i]-m[nums[i]].first].second = m[nums[i]].first;
        }
        if(m.find(nums[i]+1) != m.end()){
            m[nums[i]].second = max(m[nums[i]].second, m[nums[i]+1].second+1);
            if(m[nums[i]].second != 0) 
                m[nums[i]+m[nums[i]].second].first = m[nums[i]].second+m[nums[i]].first;
            if(m[nums[i]].first != 0) 
                m[nums[i]-m[nums[i]].first].second = m[nums[i]].first+m[nums[i]].second;
        }
        res = max(res, m[nums[i]].second+m[nums[i]].first+1);
    }
    return res;
}

//int longestConsecutive(vector<int>& nums) {
//
//}

int main(){
    //vector<int> num = {100, 4, 200, 1, 3, 2};
    vector<int> num = {1, 3, 5, 2, 4};
    printf("%d\n", longestConsecutive(num));
    return 0;
}
