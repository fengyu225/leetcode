/*The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include "header.h"

void get_perm(int n, int k, int curr, vector<char>& chars, string& curr_s){
    if(curr == n){
        curr_s += chars[0];
        return;
    }
    int len = 1;
    for(int i=1; i<=n-curr;i++)
        len *= i;
    int x = (k-1)/len;
    curr_s += chars[x];
    chars.erase(chars.begin()+x);
    get_perm(n,k-len*x,curr+1,chars,curr_s);
}

string getPermutation(int n, int k) {
    vector<char> chars;
    for(int i=1; i<=n; i++)
        chars.push_back((char)(i+'0'));
    string s="";
    get_perm(n,k,1,chars,s);
    return s;
}

int main(){
//    string str0 = getPermutation(3,5);
    string str0 = getPermutation(5,30);
    printf("%s\n", str0.c_str());
    return 0;
}
