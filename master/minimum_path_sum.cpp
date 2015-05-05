#include "header.h"

int minPathSum(vector<vector<int> > &grid) {
    if(grid.size() == 0) return 0;
    int last_l[grid[0].size()];
    int curr_l[grid[0].size()];
    vector<int*> lines;
    lines.push_back(last_l);
    lines.push_back(curr_l);
    int l = 1;
    last_l[0] = grid[0][0];
    for(int i=1; i<grid[0].size(); i++) last_l[i] = last_l[i-1]+grid[0][i];
    for(int i=1; i<grid.size(); i++){
        lines[l][0] = grid[i][0]+lines[(l+1)%2][0];
        for(int j=1;j<grid[i].size();j++)
            lines[l][j] = std::min(lines[l][j-1], lines[(l+1)%2][j])+grid[i][j];
        l = (l+1)%2;
    }
    return lines[(l+1)%2][grid[0].size()-1];
}

int main(){
//    int arr[3][3] = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    int arr[2][2] = {
        {1, 2},
        {1, 1}
    };
    vector<vector<int> > grid;
    for(int i=0; i<2; i++){
        vector<int> v;
        for(int j=0;j<2;j++)
            v.push_back(arr[i][j]);
        grid.push_back(v);
    }
    int res = minPathSum(grid);
    printf("%d\n", res);
    return 0;
}
