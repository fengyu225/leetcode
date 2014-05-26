#include<string>
#include<stdbool.h>
#include<stdio.h>

using namespace std;

string normalize(string s){
    string new_s;
    for(int i=0; i<s.size(); i++)
        if(s[i]>='A' && s[i]<='Z')
            new_s.push_back(s[i]-'A'+'a');
        else if((s[i]<='z' && s[i]>='a') || (s[i]<='9' && s[i]>='0'))
            new_s.push_back(s[i]);
        else
            continue;
    return new_s;
}


bool isPalindrome(string s){
    if(s.size()==0)
        return true;
    bool m[s.size()][s.size()];
    for(int i=0; i<s.size(); i++) m[i][i] = true;
    for(int i=2; i<=s.size(); i++)
        for(int j=0; j+i-1<s.size(); j++)
            m[j][j+i-1] = ((s[j]==s[j+i-1]) && (i==2 || m[j+1][j+i-2]))?true:false;
    return m[0][s.size()-1];
}

int main(){
    string s("A man, a plan, a canal: Panama");
    printf("%s\n", isPalindrome(normalize(s))?"true":"false");
    string s1("race a car");
    printf("%s\n", isPalindrome(normalize(s1))?"true":"false");
    return 0;
}
