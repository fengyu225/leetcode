#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

int ladderLength(string start,string end, unordered_set<string>& dict){
    if(start.compare(end) == 0)
        return 1;
    queue<string> wq;
    queue<int> lq;
    wq.push(start);lq.push(1);
    while(!wq.empty()){
        string t = wq.front();wq.pop();
        int l = lq.front();lq.pop();
        for(int i=0; i<t.size(); i++){
            char temp = t[i];
            for(char c = 'a'; c<='z'; c++){
                if(c == t[i]) continue;
                t[i] = c;
                if(t.compare(end) == 0)
                    return l+1;
                if(dict.find(t) != dict.end()){
                    wq.push(t);
                    lq.push(l+1);
                    dict.erase(word);
                }
                t[i] = temp;
            }
        }
    }
    return 0;
}

int main(){
    string start("hit");
    string end("cog");
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    printf("%d\n", ladderLength(start,end,dict));
    return 0;
}
