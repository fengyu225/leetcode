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

void get_perm(int n, int k, int curr, vector<char>& chars, string& res){
    if(curr == n){
        res += chars[0];
        return;
    }
    int p = 1;
    for(int i=1; i<=n-curr; i++) p*=i;
    int pos = (k-1)/p;
    res += chars[pos];
    chars.erase(chars.begin()+pos);
    get_perm(n, k-pos*p, curr+1, chars, res);
}

string getPermutation(int n, int k) {
    vector<char> chars;
    string res;
    for(int i=1; i<=n; i++)
        chars.push_back(i+'0');
    get_perm(n,k,1,chars,res);
    return res;
}

int main(){
    string str0 = getPermutation(3,5);
//    string str0 = getPermutation(2,1);
    printf("%s\n", str0.c_str());
    return 0;
}
