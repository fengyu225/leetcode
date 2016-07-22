/*
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.

Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.

Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<char,int>& a, pair<char,int>& b){
            return a.second<b.second;
        }
};

string rearrangeString(string str, int k) {
    int len = str.length();
    vector<int> last_pos(256, -1);
    vector<int> m(256, 0); 
    for(char c : str) m[c]++;
    priority_queue<pair<char, int>, vector<pair<char,int> >, comp> pq;
    for(int i=0; i<256; i++)
        if(m[i]>0) pq.push(make_pair(i, m[i]));
    string res = "";
    for(int i=0; i<len; i++){
        pair<char,int> t = pq.top();
        if(last_pos[t.first] == -1 || i-last_pos[t.first]>=k){
            res.push_back(t.first);
            pq.pop();
            if(t.second-1>0) pq.push(make_pair(t.first, t.second-1));
            last_pos[t.first] = i;
        }
        else{
            vector<pair<char,int> > temp_v;
            while(!pq.empty() && last_pos[pq.top().first]>=0 && i-last_pos[pq.top().first]<k){
                temp_v.push_back(pq.top());
                pq.pop();
            } 
            if(pq.empty()) return "";
            res.push_back(pq.top().first);
            pair<char,int> temp_p = pq.top();
            pq.pop();
            if(temp_p.second-1>0) pq.push(make_pair(temp_p.first, temp_p.second-1));
            last_pos[temp_p.first] = i;
            while(!temp_v.empty()){
                pq.push(temp_v.back());
                temp_v.pop_back();
            }
        }
    }
    return res;
}

int main(){
    cout<<rearrangeString("aabbcc", 3)<<endl;
    cout<<rearrangeString("aaabc", 3)<<endl;
    cout<<rearrangeString("aaadbbcc", 2)<<endl;
    return 0;
}
