#include "header.h"

vector<vector<int> > fourSum(vector<int> &num, int target) {

}

int main(){
    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = fourSum(num,0);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
