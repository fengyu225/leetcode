#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;

string minWindow(string s, string t){
    int s_len = s.size(), t_len = t.size();
    int min_len = 0, min_start = 0, min_end = 0;
    int start = 0, end = 0;
    
    return s;
}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
    string r = minWindow(s, t);
    printf("%s\n", r.c_str());
    return 0;
}
