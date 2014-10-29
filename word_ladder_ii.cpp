#include "header.h"

using namespace std;

vector<vector<string> > findLadders(string start, string end, unordered_set<string>& dict){

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
