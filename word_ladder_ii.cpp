#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

void buildResult(unordered_map<string, vector<string> >& str_prev, vector<string>& path, string curr_s, string start, vector<vector<string> >& res){
    if(curr_s.compare(start) == 0){
        res.push_back(path);
        return;
    }
    for(int i = 0; i<str_prev[curr_s].size(); i++){
        path.push_back(str_prev[curr_s][i]);
        buildResult(str_prev,path,str_prev[curr_s][i],start,res);
        path.pop_back();
    }
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string>& dict){
    unordered_map<string, vector<string> > str_prev;
    vector<unordered_set<string> > level(2);
    int curr = 0;
    int prev = 1;
    level[curr].insert(start);
    dict.insert(end);
    while(1){
        curr = curr==0?1:0;
        prev = prev==1?0:1;
        level[curr].clear();
        for(unordered_set<string>::iterator iter = level[prev].begin(); iter != level[prev].end(); iter++)
            dict.erase(*iter);
        for(unordered_set<string>::iterator iter = level[prev].begin(); iter != level[prev].end(); iter++){
            string s = *iter;
            for(int i=0; i<s.size(); i++){
                char temp_c = s[i];
                for(char c='a'; c<='z'; c++){
                    if(c == temp_c) continue;
                    s[i] = c;
                    if(dict.find(s) != dict.end()){
                        str_prev[s].push_back(*iter);
                        level[curr].insert(s);
                    }
                    s[i] = temp_c;
                }
            }
        }
        if(level[curr].empty() || level[curr].find(end) != level[curr].end())
            break;
    }
    vector<vector<string> > res;
    vector<string> path;
    if(!str_prev.empty()){
//        for(unordered_map<string, vector<string> >::iterator iter = str_prev.begin(); iter != str_prev.end(); iter++){
//            printf("%s: ", (iter->first).c_str());
//            for(int i=0; i<iter->second.size(); i++)
//                printf("%s ", iter->second[i].c_str());
//            printf("\n");
//        }
        path.push_back(end);
        buildResult(str_prev, path, end, start, res);
        for(int i=0; i<res.size(); i++)
            reverse(res[i].begin(),res[i].end());
    }
    return res;
}

int main(){
    string start("hit");
    string end("cog");
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    vector<vector<string> > r = findLadders(start,end,dict);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%s ", r[i][j].c_str());
        printf("\n");
    }
    return 0;
}
