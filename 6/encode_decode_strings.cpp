/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:

vector<string> decode(string s) {
  //... your code
  return strs;
}

So Machine 1 does:

string encoded_string = encode(strs);

and Machine 2 does:

vector<string> strs2 = decode(encoded_string);

strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

#include "header.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(string s:strs) res+=to_string(s.length())+"|"+s;
        return res; 
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int curr = 0, sz = s.length();
        while(curr<sz){
            string cnt = "";
            for(;s[curr]!= '|';cnt.push_back(s[curr]),curr++); 
            curr++;
            string temp = "";
            int c = stoi(cnt);
            for(int i=0; i<c; i++) temp.push_back(s[curr++]);
            res.push_back(temp);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(){
    Codec codec;
    vector<string> strs = {"a2", "", "ccc4"};
    cout<<codec.encode(strs)<<endl;
    vector<string> res = codec.decode(codec.encode(strs));
    cout<<res.size()<<endl;
    for(string s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}