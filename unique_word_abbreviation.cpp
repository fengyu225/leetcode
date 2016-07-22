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
    unordered_map<string, unordered_set<string> > m;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s:dictionary){
            string abbrev = getAbbrev(s);
            if(m.find(abbrev) == m.end()) m[abbrev] = unordered_set<string>();
            m[abbrev].insert(s);
        }     
    }

    bool isUnique(string word) {
        string abbrev = getAbbrev(word);
        return m.find(abbrev) == m.end() || m[abbrev].size() == 1 && *(m[abbrev].begin()) == word;
    }

    string getAbbrev(string& s){
        int sz = s.length();
        if(sz<=2) return s;
        return s.substr(0, 1)+to_string(sz-2)+s.substr(sz-1, 1);
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