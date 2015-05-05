#include "header.h"

using namespace std;

vector<int> getRow(int rowIndex){
    vector<int> last(1,1);
    vector<int> curr;
    if(rowIndex == 0) return last;
    for(int i=1; i<=rowIndex; i++){
        curr.clear();
        curr.push_back(1);
        for(int j = 1; j<i; j++)
            curr.push_back(last[j-1]+last[j]);
        curr.push_back(1);
        last = curr;
    }
    return curr;
}

int main(){
    int rowIndex = 3;
    vector<int> r = getRow(rowIndex);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
