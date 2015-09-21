/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

#include "header.h"

vector<string> generatePalindromes(string s) {

}

int main(){
    //vector<string> res = generatePalindromes("aabb");
    //vector<string> res = generatePalindromes("abc");
    print_vector<string>(generatePalindromes("aaaaaa"));
    print_vector<string>(generatePalindromes("aabb"));
    print_vector<string>(generatePalindromes("abd"));
    return 0;
}