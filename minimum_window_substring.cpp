#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;

string minWindow(string s, string t){
    int s_start = 0,s_end = s.size()-1;
    int r_start = 0,t_end = t.size()-1;
    int begin = 0, end = 0;
    int min_windows_size = s.size()+1, min_left = 0, min_right = 0;
    int count = 0;
    unordered_map<char, int> has_found;
    unordered_map<char, int> need_to_find;
    for(int i=0; i<t.size(); i++)
        if(need_to_find.find(t[i]) == need_to_find.end())
            need_to_find[t[i]] = 1;
        else
            need_to_find[t[i]]++;
    for(;end<s.size();end++){
        if(need_to_find.find(s[end]) == need_to_find.end())
            continue;
        if(has_found.find(s[end]) == has_found.end())
            has_found[s[end]] = 1;
        else
            has_found[s[end]]++;
        if(has_found[s[end]]<=need_to_find[s[end]])
            count++;
        if(count == t.size()){
            while(need_to_find.find(s[begin]) == need_to_find.end() ||
                    has_found[s[begin]]>need_to_find[s[begin]]){
                if(need_to_find.find(s[begin]) != need_to_find.end())
                    has_found[s[begin]]--;
                begin++;
            }
            int t = end-begin+1;
            if(t<min_windows_size){
                min_left = begin;
                min_right = end;
                min_windows_size = t;
            }
        }
    }
    if(min_windows_size == s.size()+1){
        string res("");
        return res;
    }
    else
        return s.substr(min_left,min_windows_size);
}

int main(){
//    string s("ADOBECODEBANC");
//    string t("ABC");
    string s("cabwefgewcwaefgcf");
    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
