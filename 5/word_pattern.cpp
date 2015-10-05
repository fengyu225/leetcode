/*
Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
Both pattern and str contains only lowercase alphabetical letters.
Both pattern and str do not have leading or trailing spaces.
Each word in str is separated by a single space.
Each letter in pattern must map to a word with length that is at least 1.
*/

#include "header.h"

bool wordPattern(string pattern, string str) {
    int p_sz = pattern.size(), s_sz = str.size();
    if(p_sz == 0) return s_sz == 0;
    stringstream ss(str);
    string curr;
    int i = 0;
    unordered_map<char,string> from;
    unordered_map<string,char> to;
    while(getline(ss, curr, ' ')){
//        cout<<curr<<endl;
        if(from.find(pattern[i]) == from.end() && to.find(curr) == to.end()){
            from[pattern[i]] = curr;
            to[curr] = pattern[i];
        }
        else if(from.find(pattern[i]) != from.end() && to.find(curr) != to.end()){
            if(from[pattern[i]] != curr || to[curr] != pattern[i]) return false;
        }
        else return false;
        i++;
    }
    return i == p_sz;
}

int main(){
    cout<<wordPattern("abba","dog cat cat dog" )<<endl; 
    cout<<wordPattern("abba","dog cat cat fish")<<endl;
    cout<<wordPattern("aaaa","dog cat cat dog" )<<endl;
    cout<<wordPattern("abba","dog dog dog dog" )<<endl;
    return 0;
}