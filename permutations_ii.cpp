#include "header.h"

vector<vector<int> > permuteUnique(vector<int> &num){
    vector<vector<int> > res;
    return res;
}

int main(){
    int arr[] = {1, 1, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permuteUnique(num);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
