#include "header.h"

void swap(vector<int>& num, int a, int b){
    int x = num[a];
    num[a] = num[b];
    num[b] = x;
}

void perm(vector<int>& num, int curr, vector<vector<int> >& res){
    if(curr == num.size()){
        res.push_back(num);
        return;
    }
    for(int i=curr; i<num.size(); i++){
        if(i!=curr && num[curr] == num[i]) continue;
        swap(num,curr,i);
        perm(num,curr+1,res);
        swap(num,curr,i);
    }
}

vector<vector<int> > permuteUnique(vector<int> &num){
    vector<vector<int> > res;
    std::sort(num.begin(), num.end());
    perm(num,0,res);
    return res;
}

int main(){
    //int arr[] = {1, 1, 2};
    //int arr[] = {1, 2, 3};
    int arr[] = {1, 2, 1, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permuteUnique(num);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
