#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex){
    vector<int> r;
    r.push_back(1);
    if(rowIndex == 0)
        return r;
    vector<int> last(1,1);
    vector<int> curr;
    for(int i=1;i<=rowIndex;i++){
        curr.push_back(1);
        for(int j=0;j<last.size()-1;j++)
            curr.push_back(last[j]+last[j+1]);
        curr.push_back(1);
        last = curr;
        curr.clear();
    }
    return last;
}

int main(){
    int rowIndex = 3;
    vector<int> r = getRow(rowIndex);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
