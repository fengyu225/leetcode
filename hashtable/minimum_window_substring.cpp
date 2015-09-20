/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include "header.h"

string minWindow(string s, string t) {

}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
//    string s("cabwefgewcwaefgcf");
//    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
