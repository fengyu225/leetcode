#include "header.h"

void dfs(vector<int>& S, int curr_idx, vector<int>& curr_set, vector<vector<int> >& res){
    if(curr_idx == S.size()){
        res.push_back(curr_set);
        return;
    }
    curr_set.push_back(S[curr_idx]);
    dfs(S,curr_idx+1,curr_set,res);
    curr_set.pop_back();
    do{
        curr_idx++;
    }while(curr_idx<S.size() && S[curr_idx] == S[curr_idx-1]);
    dfs(S,curr_idx,curr_set,res);
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > res;
    if(S.size() == 0) return res;
    std::sort(S.begin(), S.end());
    vector<int> curr_set;
    dfs(S,0,curr_set,res);
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
