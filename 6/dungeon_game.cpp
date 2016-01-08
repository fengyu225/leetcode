/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

#include "header.h"

int get_val(int curr, int req){
    if(curr>=0) return max(1, req-curr);
    return max(1, -curr+req);
}

int calculateMinimumHP(vector<vector<int> >& dungeon) {
    if(dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int> > arr(m, vector<int>(n, 0));
    // arr[i][j] min hp before enter (i,j)
    arr[m-1][n-1] = 1-min(0, dungeon[m-1][n-1]); 
    cout<<arr[m-1][n-1]<<" ";
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == m-1 && j==n-1) continue;
            if(i == m-1) arr[i][j] = get_val(dungeon[i][j], arr[i][j+1]);
            else if(j==n-1) arr[i][j] = get_val(dungeon[i][j], arr[i+1][j]);
//            else arr[i][j] = max(get_val(dungeon[i][j], arr[i][j+1]), get_val(dungeon[i][j], arr[i+1][j]));
            else arr[i][j] = get_val(dungeon[i][j], min(arr[i][j+1], arr[i+1][j]));
        }
    }
    return arr[0][0];
}

int main(){
//    vector<vector<int> > dungeon = {
//        {1, -3, 3},
//        {0, -2, 0},
//        {-3, -3, -3}
//    };
    vector<vector<int> > dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout<<calculateMinimumHP(dungeon)<<endl;
    return 0;
}