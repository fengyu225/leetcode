#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>

using std::string;
using std::vector;

vector<string> fullJustify(vector<string> &words, int L) {

}

int main(){
    string s0("This");
    string s1("is");
    string s2("an");
    string s3("example");
    string s4("of");
    string s5("text");
    string s6("justification.");
    vector<string> words;
    words.push_back(s0);
    words.push_back(s1);
    words.push_back(s2);
    words.push_back(s3);
    words.push_back(s4);
    words.push_back(s5);
    words.push_back(s6);
    vector<string> r = fullJustify(words, 16);
    for(int i=0; i<r.size(); i++)
        printf("%s\n", r[i].c_str());
    return 0;
}
