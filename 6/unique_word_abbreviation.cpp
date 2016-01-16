/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

#include "header.h"

class ValidWordAbbr {
    unordered_map<string,unordered_set<string> > abbr;
    string getAbbr(string s){
        int sz = s.length();
        if(sz<=2) return s;
        return string(1,s[0])+s.substr(1, sz-2)+string(1,s[sz-1]);
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s:dictionary){
            string ab = getAbbr(s);
            if(abbr.find(ab) == abbr.end()) abbr[ab] = unordered_set<string>();
            abbr[getAbbr(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        string ab = getAbbr(word);
        return abbr.find(ab) == abbr.end() || abbr[ab].size() == 1 && *(abbr[ab].begin()) == word;    
    }
    string getAbbr(string s){
        int sz = s.length();
        if(sz<=2) return s;
        return string(1,s[0])+s.substr(1, sz-2)+string(1,s[sz-1]);
    }

};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

int main(){
    vector<string> dictionary = {"deer", "door", "cake", "card"};
    ValidWordAbbr vwa(dictionary);
    cout<<vwa.isUnique("dear")<<endl;
    cout<<vwa.isUnique("cart")<<endl;
    cout<<vwa.isUnique("cane")<<endl;
    cout<<vwa.isUnique("make")<<endl;
    return 0;
}