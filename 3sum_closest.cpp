#include "header.h"

int threeSumClosest(vector<int> &num, int target) {
    if(num.size() == 0) return 0;
    std::sort(num.begin(), num.end());
    int a=-1,b=-1,c=-1;
    int diff = INT_MAX, res=INT_MAX;
    for(int i=0; i<num.size()-2;i++){
        int j=i+1,k=num.size()-1;
        while(j<k){
            int sum = num[i]+num[j]+num[k];
            if(sum == target) return sum;
            if(abs(sum-target)<diff){
                diff = abs(sum-target);
                res = sum;
            }
            if(sum>target)
                k--;
            else
                j++;
        }
    }
    return res;
}

int main(){
    int arr[] = {-1, 2, 1, -4};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = threeSumClosest(num, 1);
    printf("%d\n", res);
    return 0;
}
