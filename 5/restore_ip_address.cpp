/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "header.h"

void search(string& s, int curr, int dot, string& temp, string& curr_s, vector<string>& res){
    if(curr == s.length()){
        if(dot == 3) res.push_back(temp);
        return;
    }
    string temp_t = temp;
    string curr_s_t = curr_s;
    if(curr_s.length()>0){
        int curr_s_int = stoi(curr_s);
        if(curr_s_int<=255 && curr_s_int>0 && curr_s[0]!='0' || curr_s_int==0 && dot>0){
            if(dot<3){
                temp += curr_s;
                temp += '.';
                curr_s = s[curr];
                search(s, curr+1, dot+1, temp, curr_s, res);
            }
        }
    }
    string new_curr_s = curr_s+s[curr];
    int curr_s_int = stoi(new_curr_s);
    if(curr_s_int<=255 && curr_s_int>0 && new_curr_s[0]!='0' || curr_s_int == 0 && dot>0)
        search(s, curr+1, dot, temp, new_curr_s, res);
    temp = temp_t;
    curr_s = curr_s_t;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.length()>12) return res;
    if(s.length() == 0) return res;
    string temp = "";
    string curr_s = "";
    search(s, 0, 0, temp, curr_s, res);
    return res;
}

int main(){
    string s("010010");
    vector<string> res = restoreIpAddresses(s);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
