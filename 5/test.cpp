/*
(x, y) -> (x, y+1) -> (x+1, y+1) -> (x-1, y+1) -> (x-1, y-1) -> (x-1, y+2) -> (x+2, y+2)
*/

#include "header.h"

void print_(int n){
    int last_x = 0, last_y = 0;
    int arr[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    cout<<last_x<<", "<<last_y<<endl;
    for(int i=1; i<n; i++){
        int new_x = last_x+((i-1)/2+1)*arr[(i-1)%4][0];
        int new_y = last_y+((i-1)/2+1)*arr[(i-1)%4][1];
        cout<<new_x<<", "<<new_y<<endl;
        last_x = new_x;
        last_y = new_y;
    }
}

int main(){
    print_(7);
    return 0;
}