#include "header.h"

unordered_map<char,int> getLongestRun(string s){
	unordered_map<char,int> res;
	int sz = s.length();
	if(sz == 0) return res;
	int l=0, r = 0;
	while(r<sz){
		if(s[r] != s[l]){
			res[s[l]] = max(res[s[l]], r-l);
			l = r;
		}
		r++;
	}
	res[s[l]] = max(res[s[l]], r-l);
	return res;
}

int main(){
    unordered_map<char,int> r = getLongestRun("abcdcccddcc");
    for(auto p:r){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}