/*
 *  Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 *  For example, given
 *  s = "leetcode",
 *  dict = ["leet", "code"].
 *
 *  Return true because "leetcode" can be segmented as "leet code". 
 */

#include "header.h"

bool wordBreak(string s, unordered_set<string>& dict){
    if(s.size() == 0) return false;
    s = '#' + s;
    bool arr[s.size()];
    arr[0] = true;
    for(int i=1; i<s.size(); i++){
        for(int k=0; k<i; k++){
            arr[i] = arr[k] && dict.find(s.substr(k+1,i-k)) != dict.end();
            if(arr[i])
                break;
        }
    }
    for(int i=0; i<s.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
    return arr[s.size()-1];
}

int main(){
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    string s("leetcodeleetleet");
    printf("%d\n", wordBreak(s,dict));
    return 0;
}
