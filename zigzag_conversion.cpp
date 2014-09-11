#include "header.h"

/*

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
*/

string convert(string s, int nRows){
    if(s.length()==0 || nRows <=0)  
        return "";  
    if(nRows == 1)  
        return s;  
    string res = ""; 
    int size = 2*nRows-2;  
    for(int i=0;i<nRows;i++)  
    {  
        for(int j=i;j<s.length();j+=size)  
        {  
            res += s[j];  
            if(i!=0 && i!=nRows-1 && j+size-2*i<s.length())  
                res+=s[j+size-2*i];  
        }                  
    }  
    return res;  
}

int main(){
    string s("PAYPALISHIRING");
//    string s("ABC");
    string res = convert(s,3);
    printf("%s\n", res.c_str());
    return 0;
}
