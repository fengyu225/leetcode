#include "header.h"

void dfs(string& s, int curr, vector<int>& pos, vector<string>& res){
    if(curr>=s.size()){
        string x = s;
        if(pos.size()==4){
            for(int i=0; i<pos.size()-1; i++)
                x.insert(pos[i]+i,".");
            res.push_back(x);
        }
        return;
    }
    if(pos.size()>=4) return;
    if(s[curr] == '0'){
        pos.push_back(curr+1);
        dfs(s,curr+1,pos,res);
        pos.pop_back();
        return;
    }
    for(int i=curr;i<s.size();i++){
        int temp = std::stoi(s.substr(curr,i-curr+1));
        if(temp>255)
            break;
        pos.push_back(i+1);
        dfs(s,i+1,pos,res);
        pos.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.size()<4) return res;
    vector<int> pos;
    dfs(s,0,pos,res);
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
