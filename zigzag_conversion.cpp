#include "header.h"

string convert(string s, int nRows){
    if(nRows == 1) return s;
    string before = "";
    string after = "";
    for(int i=0; i<nRows/2; i++){
        for(int j=i;j<s.size();j+=(nRows+1)/2*2)
            before+=s[j];
    }
    if(nRows%2==1){
        for(int i=nRows/2;i<s.size();i+=(nRows+1)/2)
            before+=s[i];
    }
    for(int i=(nRows+1)/2;i<nRows;i++){
        for(int j=i;j<s.size();j+=(nRows+1)/2*2)
            after+=s[j];
    }
    return before+after;
}

int main(){
    //string s("PAYPALISHIRING");
    string s("ABC");
    string res = convert(s,3);
    printf("%s\n", res.c_str());
    return 0;
}
