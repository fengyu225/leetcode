/*
Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
Both pattern and str contains only lowercase alphabetical letters.
Both pattern and str do not have leading or trailing spaces.
Each word in str is separated by a single space.
Each letter in pattern must map to a word with length that is at least 1.
*/

#include "header.h"

bool wordPattern(string pattern, string str) {
    return false;
}

int main(){
    cout<<wordPattern("abba","dog cat cat dog" )<<endl; 
    cout<<wordPattern("abba","dog cat cat fish")<<endl;
    cout<<wordPattern("aaaa","dog cat cat dog" )<<endl;
    cout<<wordPattern("abba","dog dog dog dog" )<<endl;
    return 0;
}