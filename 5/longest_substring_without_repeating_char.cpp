#include "header.h"

int lengthOfLongestSubstring(string s) {
	if(s.length()<2) return s.length();
	int sz = s.length();
	int map[127] = {0};
	int l = 0, r=1;
	map[s[l]] = 1;
	int res = 1;
	while(r<sz){
		if(map[s[r]]==0){
			map[s[r]]++;
			r++;
			res = max(res,r-l);
			continue;
		}
		while(map[s[r]]>0){
			map[s[l]]--;
			l++;
		}
		map[s[r]]=1;
		res = max(res,r-l+1);
		r++;
	}
	return res;
}	

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
