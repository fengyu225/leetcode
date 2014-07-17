#include "header.h"

void swap(vector<int>& num, int i, int j){
    int x = num[i];
    num[i] = num[j];
    num[j] = x;
}

void search(int curr_idx, vector<int>& num, vector<vector<int> >& res){
    if(curr_idx == num.size()){
        res.push_back(num);
        return ;
    }
    for(int i=curr_idx; i<num.size(); i++){
        swap(num,i,curr_idx);
        search(curr_idx+1,num,res);
        swap(num,i,curr_idx);
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > res;
    search(0,num,res);
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permute(v);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
