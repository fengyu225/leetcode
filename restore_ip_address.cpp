/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "header.h"

void search(string& s, int curr, vector<int>& pos, vector<string>& res){
    if(curr >= s.length()){
        if(pos.size() == 4){
            string x = s;
            for(int i=0; i<pos.size(); i++) x.insert(i+pos[i], ".");
            x=x.substr(0,x.size()-1);
            res.push_back(x);
        } 
        return;
    }
    if(pos.size() >= 4) return;
    if(s[curr] == '0'){
        pos.push_back(curr+1);
        search(s, curr+1, pos, res);
        pos.pop_back();
        return;
    }
    for(int i=curr; i<s.length(); i++){
        string temp = s.substr(curr, i-curr+1);
        int temp_num = stoi(temp);
        if(temp_num>255) return;
        pos.push_back(i+1);
        search(s,i+1,pos,res);
        pos.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<int> pos;
    search(s, 0, pos, res);
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
