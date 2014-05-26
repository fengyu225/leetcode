#include<stdlib.h>
#include<vector>
#include<stdio.h>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& num){
    unordered_map<int,int> m;
    int max = 0;
    for(int i=0; i<num.size(); i++)
        m.insert(pair<int,int>(num[i],1));
    for(int i=0; i<num.size(); i++){
        if(m[num[i]] == 0)
            continue;
        int j=num[i]-1;
        int a = 1;
        while(1){
            if(m.find(j) == m.end())
                break;
            m[j] = 0;
            j--;
            a++;
        }
        j = num[i]+1;
        while(1){
            if(m.find(j) == m.end())
                break;
            m[j] = 0;
            j++;
            a++;
        }
        max = a>max?a:max;
    }
    return max;
}

int main(){
    int arr[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    printf("%d\n", longestConsecutive(num));
    return 0;
}
