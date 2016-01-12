/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

#include "header.h"

vector<string> search(int n, int x){
    vector<string> res;
    if(n == 0) return res;
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        res.push_back("8");
    }
    else if(n == 2){
        if(n != x) res.push_back("00");
        res.push_back("11");
        res.push_back("88");
        res.push_back("69");
        res.push_back("96");
    }
    else{
        vector<string> temp = search(n-2, x);
        for(auto s:temp){
            if(n!=x) res.push_back("0"+s+"0");
            res.push_back("1"+s+"1");
            res.push_back("8"+s+"8");
            res.push_back("6"+s+"9");
            res.push_back("9"+s+"6");
        } 
    }
    return res; 
}

void findStrobogrammatic(int n, vector<string>& res) {
    res = search(n, n);
    return;
}

int search_count(int n, int x){
    if(n == 0) return 0;
    if(n == 1) return 3;
    else if(n == 2){
        if(n != x) return 5;
        return 4;
    }
    else{
        int temp = search_count(n-2, x);
        if(n!=x) return 5*temp;
        else return 4*temp;
    }
}

int countStrobogrammatic(int n) {
    return search_count(n, n);
}

int compare(string s, string t){
    if(s.length()<t.length()) return -1*compare(t, s);
    if(s.length() == t.length()) return s.compare(t);
    for(int i=0; i<s.length()-t.length(); i++) t="0"+t;
    return s.compare(t);
}

int strobogrammaticInRange(string low, string high) {
    int l_sz = low.length();
    int h_sz = high.length();
    if(l_sz>h_sz || l_sz == h_sz && low.compare(high)>0) return 0;
    vector<string> l, h;
    findStrobogrammatic(l_sz, l);
    findStrobogrammatic(h_sz, h);
    int res = 0;
    for(int i=l_sz+1; i<h_sz; i++){
        res += countStrobogrammatic(i);
    }
    for(auto s:l){
        if(compare(s, low)>=0 && compare(s,high)<=0) res++;
    }
    if(l_sz == h_sz) return res;
    for(auto s:h){
        if(compare(s, low)>=0 && compare(s,high)<=0) res++;
    }
    return res;
}

int main(){
    cout<<strobogrammaticInRange("50", "100")<<endl;
    return 0;
}