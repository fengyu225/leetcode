#include "header.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res;
    return res;
}

int main(){
    vector<vector<int> > res = generateMatrix(3);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
