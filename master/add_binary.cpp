#include "header.h"

string addBinary(string a, string b) {
    string result;
    int i=a.size()-1, j=b.size()-1;
    int carry = 0;
    while(i>=0 || j>=0){
        int a_curr = i>=0?(int)(a[i]-'0'):0;
        int b_curr = j>=0?(int)(b[j]-'0'):0;
        result = (char)((a_curr+b_curr+carry)%2+'0')+result;
        carry = (a_curr+b_curr+carry)>1?1:0;
        if(i>=0) i--;
        if(j>=0) j--;
    }
    if(carry)
        result = (char)(carry+'0')+result;
    return result;
}

int main(){
    string a("11");
    string b("1");
    string res = addBinary(a,b);
    printf("%s\n", res.c_str());
    return 0;
}
