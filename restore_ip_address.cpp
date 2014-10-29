#include "header.h"

void dfs(string& s, int curr, vector<int>& ip, vector<string>& res){
    if(curr>=s.size()){
        if(ip.size() == 4){
            string x = s;
            for(int i=0; i<ip.size(); i++)
                x.insert(i+ip[i],".");
            x = x.substr(0,x.size()-1);
            res.push_back(x);
        }
        return;
    }
    if(ip.size() >= 4) return;
    if(s[curr] == '0'){
        ip.push_back(curr+1);
        dfs(s,curr+1,ip,res);
        ip.pop_back();
        return;
    }
    for(int i=curr; i<s.size(); i++){
        string x = s.substr(curr,i-curr+1);
        int x_int = std::stoi(x);
        if(x_int>255) break;
        ip.push_back(i+1);
        dfs(s,i+1,ip,res);
        ip.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.size()<4) return res;
    vector<int> ip;
    dfs(s,0,ip,res);
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
