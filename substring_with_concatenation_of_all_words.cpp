#include "header.h"

vector<int> findSubstring(string S, vector<string>& L){
    vector<int> res;
    if(L.size()==0 || S.size()<L[0].size()*L.size()) return res;
    unordered_map<string, int> dict;
    unordered_map<string, int> temp;
    int l_w_size = L[0].size();
    int l_size = L.size();
    for(int i=0; i<L.size(); i++)
        if(dict.find(L[i])==dict.end()) dict[L[i]]=1;
        else dict[L[i]]++;
    for(int x=0; x<L.size(); x++) temp[L[x]]=0;
    for(int i=0; i<=S.size()-l_w_size*l_size; i++){
        int j=i;
        while(j-i<l_size*l_w_size){
            if(dict.find(S.substr(j,l_w_size)) == dict.end() || temp[S.substr(j,l_w_size)]>dict[S.substr(j,l_w_size)])
                break;
            temp[S.substr(j,l_w_size)] += 1;
            j+=l_w_size;
        }
        for(int x=0; x<L.size(); x++) temp[L[x]]=0;
        if(j-i<l_size*l_w_size)
            continue;
        res.push_back(i);
    }
    return res;
}

int main(){
//    string S("barfoothefoobarman");
//    string l0("foo");
//    string l1("bar");
    string S("aaa");
    string l0("a");
    string l1("a");
    vector<string> L;
    L.push_back(l0);
    L.push_back(l1);
    vector<int> r = findSubstring(S,L);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
