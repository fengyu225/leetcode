#include "header.h"

//1, 2, 3, 4

void search(int n, int k, int curr_head, vector<int>& vec, vector<vector<int> >& res){
    if(vec.size() == k){
        res.push_back(vec);
        return;
    }
    if(curr_head>n) return;
//    if(vec.size()+n-curr_head+1>k) return;
    vec.push_back(curr_head);
    search(n,k,curr_head+1,vec,res);
    vec.pop_back();
    search(n,k,curr_head+1,vec,res);
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    if(k>n) return res;
    vector<int> vec;
    search(n,k,1,vec,res);
    return res;
}

int main(){
    vector<vector<int> > res = combine(4,2);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
