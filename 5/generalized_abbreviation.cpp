/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

#include "header.h"

void search(string& word, int curr, int max_n, string& temp, vector<string>& res, bool char_only){
    int sz = word.length();
    if(curr == sz){
        res.push_back(temp);
        return;
    }
    string a = temp;
    temp+=word[curr];
    search(word, curr+1, max_n-1, temp,res, false);
    temp = a;
    if(!char_only){
        for(int i=1; i<=max_n; i++){
            string a = temp;
            temp += to_string(i);
            search(word, curr+i, max_n-i, temp, res, true);
            temp = a;
        }
    }
}

vector<string> generateAbbreviations(string word) {
    vector<string> res;
    string temp = "";
    search(word, 0, word.length(), temp, res, false);
    return res;
}

int main(){
    vector<string> res = generateAbbreviations("word");
    print_vector<string>(res);
    return 0;
}