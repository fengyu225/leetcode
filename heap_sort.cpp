#include "header.h"

void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void siftup(vector<int>& arr, int end){
    int curr = end;
    int parent = (curr-1)/2;
    while(parent>=0){
        if(arr[parent]>=arr[curr]) break;
        swap(arr, parent, curr);
        curr = parent;
        parent = (curr-1)/2;
    }
}

void siftdown(vector<int>& arr, int end){
    int curr = 0;
    if(end == 0) return;
    while(2*curr+1<=end){
        int child = 2*curr+2<=end && arr[2*curr+2]>arr[2*curr+1]?2*curr+2:2*curr+1;
        if(arr[curr]>arr[child]) break;
        swap(arr, curr, child);
        curr = child;
    }
}

void h_sort(vector<int>& arr){
    int sz = arr.size();
    if(sz<2) return;
    for(int i=1; i<sz; i++) siftup(arr, i);
    for(int i=sz-1; i>0; i--){
        swap(arr, i, 0);
        siftdown(arr, i-1);
    }
}

int main(){
    int arr[] = {7, 9, 8, -1, -100, 343, 1221};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    h_sort(v_arr);
    for(int i=0; i<v_arr.size(); i++) cout<<v_arr[i]<<" ";
    cout<<endl;
    return 0;
}