/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.


1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/

#include "header.h"

string strAdd(string &v1, string &v2){
    string res = "";
    int carry = 0;
    int len1 = v1.size(), len2 = v2.size();

    for(int i = len1-1, j = len2-1; i >= 0 || j >= 0; i--, j--){
        int n1 = (i >= 0) ? v1[i]-'0' : 0;
        int n2 = (j >= 0) ? v2[j]-'0' : 0;
        res = to_string((n1 + n2 + carry) % 10) + res;
        carry = (n1 + n2 + carry) > 9;
    }

    return (carry) ? "1" + res : res;
}

bool isAdditive(string &num, string v1, string v2, int idx, int n){
    string sumStr = strAdd(v1, v2);
    if(num.compare(idx, sumStr.size(), sumStr) == 0)
        return (idx + sumStr.size() >= n || isAdditive(num, v2, sumStr, idx+sumStr.size(), n));
    else
        return false;
}

bool isAdditiveNumber(string num) {
    int n = num.size();
    bool found = 0;
    for(int len1 = 1; len1 <= (n/2); len1++){
        for(int len2 = 1; len2 <= (n/2); len2++){
            found = isAdditive(num, num.substr(0, len1), num.substr(len1, len2), len1+len2, n);
            if(found)   
                return true;
        }
    }
    return false;
}

int main(){
    cout<<isAdditiveNumber("199100199")<<endl;
    return 0;
}