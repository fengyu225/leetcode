#include<string>
#include<stdbool.h>
#include<stdio.h>

using namespace std;

bool is_alpha_num(char c){
    return c<='Z' && c>='A' || c<='z' && c>='a' || c<='9' && c>='0';
}

bool is_equal(char a, char b){
    return a==b || a-b == 'A'-'a' || a-b=='a'-'A';
}

bool isPalindrome(string s){
    if(s.size()<2) return true;
    int l=0,r=s.size()-1;
    while(l<r){
        if(!is_alpha_num(s[l])){
            l++;
            continue;
        }
        if(!is_alpha_num(s[r])){
            r--;
            continue;
        }
        if(!is_equal(s[l], s[r])) return false;
        l++;r--;
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
