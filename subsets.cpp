#include "header.h"

vector<vector<int> > subsets(vector<int> &S) {
    unsigned int sz = S.size();
    unsigned int c = 1U<<sz;
    vector<vector<int> > res;
    for(unsigned int i=0; i<c; i++){
        int x = i; int temp = 0;
        vector<int> v;
        while(x){
            if(x&1U) v.push_back(S[temp]);
            x >>=1;
            temp++;
        }
        res.push_back(v);
    }
    return res;
}

int main(){
    int arr[] = {1, 2, 3};
    vector<int> S(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = subsets(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
