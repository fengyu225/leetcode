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

void getNum(string& s, vector<int>& res){
    int curr = 0, sz = s.length();
    string temp = "";
    while(curr<sz){
        if(s[curr] == '.'){
            res.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp += s[curr];
        }
        curr++;
    }
    if(temp.length()>0) res.push_back(stoi(temp));
}

int compareVersion(string version1, string version2){
    vector<int> v1_arr, v2_arr;
    getNum(version1, v1_arr);
    getNum(version2, v2_arr);
    int curr = 0;
    while(curr<v1_arr.size() || curr<v2_arr.size()){
        int temp_1 = curr<v1_arr.size()?v1_arr[curr]:0;
        int temp_2 = curr<v2_arr.size()?v2_arr[curr]:0;
        if(temp_1>temp_2) return 1;
        if(temp_1<temp_2) return -1;
        curr++;
    }
    return 0;
}

int main(){
    cout<<compareVersion("10.6.5","10.6")<<endl;
    cout<<compareVersion("0","1")<<endl;
    cout<<compareVersion("0.1","1.1")<<endl;
    cout<<compareVersion("1.1","1.2")<<endl;
    cout<<compareVersion("1.2","13.7")<<endl;
    return 0;
}