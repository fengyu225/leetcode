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
typedef unsigned char UCHAR;
const static int MAX_CNT = 255;

// Encodes a list of strings to a single string.
string encode(vector<string>& strs) {
    string ret;
    for(auto &s : strs)
    {
        int i = 0, len = s.length();

        while(i < len)
        {
            UCHAR c = s[i];
            UCHAR cnt = 1;
            while(i < len - 1 && s[i + 1] == c && cnt < (MAX_CNT - 1))
            {
                i ++; cnt ++;
            }
            ret += UCHAR(cnt);
            ret += UCHAR(c);

            i ++;
        }
        ret += UCHAR(MAX_CNT); // 0xFF: end
    }
    cout<<ret<<endl;
    return ret;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) 
{
    vector<string> ret;

    size_t len = s.length();
    string cur; int inx = 0;
    while(inx < len)
    {
        UCHAR cnt = s[inx];
        if(cnt == UCHAR(MAX_CNT))
        {
            ret.push_back(cur);
            cur = "";
            inx ++;
            continue;
        }
        //
        UCHAR c = s[inx + 1];
        for(UCHAR i = 0; i < cnt; i ++)    cur += c;
        inx += 2;                        
    }
    return ret;
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(){
    Codec codec;
    vector<string> strs = {"aaa", "bbb"};
    vector<string> res = codec.decode(codec.encode(strs));
    cout<<res.size()<<endl;
    for(string s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}