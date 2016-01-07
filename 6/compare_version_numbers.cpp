/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/

#include "header.h"

int comp(string a, string b){
    int a_val = stoi(a);
    int b_val = stoi(b);
    return a_val == b_val?0:a_val<b_val?-1:1;
}

int compareVersion(string version1, string version2) {
    int sz1 = version1.length(), sz2 = version2.length();
    int a=-1, b=-1;
    while(a<sz1 && b<sz2){
        int temp_a = a+1, temp_b = b+1;
        while(temp_a<sz1 && version1[temp_a] != '.') temp_a++;
        while(temp_b<sz2 && version2[temp_b] != '.') temp_b++;
        int temp_res = comp(version1.substr(a+1,temp_a-a-1), version2.substr(b+1,temp_b-b-1));
        if(temp_res != 0) return temp_res;
        a = temp_a; b=temp_b;
    }
    return a<sz1?1:b<sz2?-1:0;
}

int main(){
    cout<<compareVersion("10.6.5","10.6")<<endl;
    cout<<compareVersion("0","1")<<endl;
    cout<<compareVersion("0.1","1.1")<<endl;
    cout<<compareVersion("1.1","1.2")<<endl;
    cout<<compareVersion("1.2","13.7")<<endl;
    return 0;
}