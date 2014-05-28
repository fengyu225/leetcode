#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<vector<int> > generate(int numRows){
    vector<vector<int> > result;
    if(numRows == 0)
        return result;
    vector<int> r0(1, 1);
    result.push_back(r0);
    vector<int> last = r0;
    for(int i=1; i<numRows; i++){
        vector<int> t;
        t.push_back(1);
        for(int j=0; j<=(int)last.size()-2; j++)
            t.push_back(last[j]+last[j+1]);
        t.push_back(1);
        last = t;
        result.push_back(t);
    }
    return result;
}

int main(){
    int numRows = 5;
    vector<vector<int> > r = generate(numRows);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
