#include "header.h"

string longestPalindrome(string s) {
    if(s.size() <=1) return s;
    bool arr[s.size()][s.size()];
    memset(arr,0,s.size()*s.size()*sizeof(bool));
    int begin = -1,max=0;
    for(int i=0; i<s.size(); i++) arr[i][i] = true;
    for(int i=0; i+1<s.size(); i++)
        if(s[i]==s[i+1]){
            arr[i][i+1] = true;
            max = 2;
            begin = i;
        }
    for(int k=3; k<=s.size(); k++){
        for(int i=0;i+k-1<s.size();i++){
            if(s[i] == s[i+k-1] && arr[i+1][i+k-2]){
                arr[i][i+k-1] = true;
                if(k>max){
                    begin = i;
                    max = k;
                }
            }
        }
    }
    return s.substr(begin,max);
}


string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}


int main(){
    string s0 = longestPalindrome("abacdfgdcaba");
    printf("%s\n", s0.c_str());
    return 0;
}
