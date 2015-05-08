#include "header.h"

int lengthOfLongestSubstring(string s) {
	if(s.length()<2) return s.length();
	int sz = s.length();
	int map[127] = {0};
	int l = 0, r=0;
	while(r<sz){
		
	}
}	

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
