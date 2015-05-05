#include<string>
#include<stdbool.h>
#include<stdio.h>

using namespace std;

bool isPalindrome(string s){
    if(s.size() == 0 || s.size() == 1) return true; 
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]<='Z' && s[l]>='A')
            s[l] = s[l]-'A'+'a';
        if(s[r]<='Z' && s[r]>='A')
            s[r] = s[r]-'A'+'a';
        if(!((s[l]>='a' && s[l]<='z') || (s[l]<='9' && s[l]>='0'))){
            l++;
            continue;
        }
        if(!((s[r]>='a' && s[r]<='z') || (s[r]<='9' && s[r]>='0'))){
            r--;
            continue;
        }
        if(s[l] != s[r])
            return false;
        else{
            l++;
            r--;
        }
    }
    return true;
}

int main(){
    string s("A man, a plan, a canal: Panama");
    printf("%s\n", isPalindrome(s)?"true":"false");
    string s1("race a car");
    printf("%s\n", isPalindrome(s1)?"true":"false");
    return 0;
}
