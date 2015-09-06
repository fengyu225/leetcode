/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

#include "header.h"

int hIndex(vector<int>& citations) {
    int sz = citations.size();
    if(sz == 0) return 0;
    int l = 0, r=sz-1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(citations[m]>=sz-m) r=m;
        else l=m+1;
    }
    return citations[l]>=sz-l?sz-l:citations[r]>=sz-r?sz-r:0;
}

int main(){
    //vector<int> citations = {0, 1, 3, 5, 6};
    vector<int> citations = {1};
    cout<<hIndex(citations)<<endl;
    return 0;
}