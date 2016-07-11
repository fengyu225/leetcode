/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True

Example 2:
Input: x = 2, y = 6, z = 5
Output: False
*/

#include "header.h"

bool canMeasureWater(int x, int y, int z) {
    if(x+y < z) return false;
    if(z == 0) return true;
    if(x == z || y == z || x+y == z) return true;
    if(x>y) swap(x,y);
    if(x == 0) return false;
    int b = (y/x+1)*x%y; 
    int curr = b;
    while(1){
        if(curr+x == z || curr+y == z || curr == z) return true;
        int temp = (((y-curr)/x+1)*x+curr)%y;
        if(temp == b) return false;
        curr = temp;
    }
}

int main(){
    cout<<canMeasureWater(13, 11, 1)<<endl;
//    cout<<canMeasureWater(3, 4, 5)<<endl;
//    cout<<canMeasureWater(4, 6, 3)<<endl;
    return 0;
}
