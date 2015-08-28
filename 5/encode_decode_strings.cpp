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
    // idea is change ["a2", "a|a3", "ccc4"] to "5,2,4,4a2a|a3ccc4"
    // 2,4,4 are string len
    // 5 is length of string "2,4,4"
    string encode(vector<string>& strs) {
        string res = "";
        string temp = "";
        for(string s:strs){
            res += s;
            temp += to_string(s.length());
            temp += ",";
        }
        if(temp.length() != 0) temp.pop_back();
        res = to_string(temp.length())+","+temp+res;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if(s.length() == 0) return res;
        int curr = 0;
        for(;s[curr]!=',';curr++);
        int prefix_len = stoi(s.substr(0, curr));
        string prefix = s.substr(curr+1, prefix_len);
        string concat_str = s.substr(curr+prefix_len+1, s.length()-curr-prefix_len-1);
        stringstream ss(prefix);
        string pos;
        int start = 0;
        while(getline(ss, pos, ',')){
            int temp = stoi(pos);
            res.push_back(concat_str.substr(start, temp));
            start += temp;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(){
    Codec codec;
    vector<string> strs = {"a2", "a|a3", "ccc4"};
    vector<string> res = codec.decode(codec.encode(strs));
    for(string s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}