/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

#include "header.h"

vector<bool> versions(2126753391, false);

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n>2 && isBadVersion(n) && !isBadVersion(n-1)) return n;
        int l = 1, r=n;
        while(l+1<r){
            int m = l+(r-l)/2;
            if(isBadVersion(m)) r=m;
            else l=m+1;
        }
        return isBadVersion(l)?l:r;
    }
};

bool isBadVersion(int version){
    //2126753390 versions, 1702766719 is the first bad version.
    return versions[version];
}

int main(){
    Solution s;
    for(int i=1702766719; i<=2126753390; i++) versions[i] = true;
    cout<<s.firstBadVersion(2126753390)<<endl;
    return 0;
}