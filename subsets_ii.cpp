#include "header.h"

void subsets(vector<int>& S, int curr, vector<int>& v, vector<vector<int> >& res){
    if(curr == S.size()){
        res.push_back(v);
        return;
    }
    v.push_back(S[curr]);
    subsets(S,curr+1,v,res);
    v.pop_back();
    while(curr+1<S.size() && S[curr]==S[curr+1]) curr++;
    subsets(S,curr+1,v,res);
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > res;
    if(S.size() == 0)
        return res;
    std::sort(S.begin(),S.end());
    vector<int> v;
    subsets(S,0,v,res);
    return res;
}

int main(){
    int s_arr[] = {1, 2, 2};
    /*
     * [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
     */
    vector<int> S(s_arr,s_arr+sizeof(s_arr)/sizeof(s_arr[0]));
    vector<vector<int> > res = subsetsWithDup(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
