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
        if(i!=curr && num[i] == num[i-1] || i!=curr && num[i] == num[curr]) continue;
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

//bool noswap(int k, int i, const vector<int> num){
//    for (int j=k;j<i;j++){
//        if (num[j]==num[i]){
//            return true;
//        }
//    }
//    return false;
//}
//
//void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
//    if (k==n){
//        res.push_back(num);
//    }else{
//        for (int i=k;i<=n;i++){
//             
//            if (noswap(k,i,num)){continue;}
//             
//            int tmp = num[k];
//            num[k]=num[i];
//            num[i]=tmp;
//             
//            perm(num,k+1,n,res);
//             
//            tmp = num[k];
//            num[k]=num[i];
//            num[i]=tmp;
//        }
//    }
//}
//vector<vector<int> > permuteUnique(vector<int> &num) {
//    // Start typing your C/C++ solution below
//    // DO NOT write int main() function
//    vector<vector<int> > res;
//    perm(num,0,(num.size()-1),res);
//    return res;
//}

int main(){
    //int arr[] = {1, 1, 2};
    //int arr[] = {1, 2, 3};
//    int arr[] = {1, 2, 1, 2};
    int arr[] = {-1,2,0,-1,1,0,1};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permuteUnique(num);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
