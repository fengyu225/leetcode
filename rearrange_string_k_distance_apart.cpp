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

// change made to get it runs faster:
// 1. Not using custom compare function for priority_queue
// 2. Not making pairs if unnecessary

string rearrangeString(string str, int k) {
    int len = str.length();
    vector<int> last_pos(256, -1);
    vector<int> m(256, 0); 
    for(char c : str) m[c]++;
    priority_queue<pair<int, char>, vector<pair<int, char> > > pq;
    for(int i=0; i<256; i++)
        if(m[i]>0) pq.push(make_pair(m[i], i));
    string res = "";
    for(int i=0; i<len; i++){
        pair<int, char> t = pq.top();
        if(last_pos[t.second] == -1 || i-last_pos[t.second]>=k){
            res.push_back(t.second);
            pq.pop();
            t.first--;
            if(t.first>0) pq.push(t);
            last_pos[t.second] = i;
        }
        else{
            vector<pair<int, char> > temp_v;
            while(!pq.empty() && last_pos[pq.top().second]>=0 && i-last_pos[pq.top().second]<k){
                temp_v.push_back(pq.top());
                pq.pop();
            } 
            if(pq.empty()) return "";
            res.push_back(pq.top().second);
            pair<int, char> temp_p = pq.top();
            pq.pop();
            temp_p.first--;
            if(temp_p.first>0) pq.push(temp_p);
            last_pos[temp_p.second] = i;
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
