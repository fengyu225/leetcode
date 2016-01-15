/*
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

#include "header.h"

//int numWays(int n, int k) {
//    if(n == 0 || k == 0) return 0;
//    vector<int> arr0(n, 0); //all different
//    vector<int> arr1(n, 0); //exist two same 
//    arr0[0] = k;
//    for(int i=1; i<n; i++){
//        arr0[i] = (k-1)*arr0[i-1];
//        arr1[i] = (k-1)*arr1[i-1]+arr0[i-1];
//    }
//    for(int c:arr0) cout<<c<<" ";
//    cout<<endl;
//    for(int c:arr1) cout<<c<<" ";
//    cout<<endl;
//    return arr0[n-1]+arr1[n-1];
//}
/*
If n == 1, there would be k-ways to paint.

if n == 2, there would be two situations:

2.1 You paint same color with the previous post: k*1 ways to paint, named it as same
2.2 You paint differently with the previous post: k*(k-1) ways to paint this way, named it as dif
So, you can think, if n >= 3, you can always maintain these two situations, You either paint the same color with the previous one, or differently.

Since there is a rule: "no more than two adjacent fence posts have the same color."

We can further analyze:

from 2.1, since previous two are in the same color, next one you could only paint differently, and it would form one part of "paint differently" case in the n == 3 level, and the number of ways to paint this way would equal to same*(k-1).
from 2.2, since previous two are not the same, you can either paint the same color this time (dif*1) ways to do so, or stick to paint differently (dif*(k-1)) times.
Here you can conclude, when seeing back from the next level, ways to paint the same, or variable same would equal to dif*1 = dif, and ways to paint differently, variable dif, would equal to same*(k-1)+dif*(k-1) = (same + dif)*(k-1)
*/

int numWays(int n, int k) {
    if(n == 0 || k == 0) return 0;
    if(n == 1) return k;
    if(n == 2) return k+k*(k-1);
    int same = k, diff = k*(k-1);
    for(int i=3;i<=n;i++){
        int new_same = diff;
        int new_diff = (same+diff)*(k-1);
        same = new_same;
        diff = new_diff;
    }
    return same+diff;
}

int main(){
    cout<<numWays(4, 2)<<endl;
    return 0;
}