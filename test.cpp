#include "header.h"

int f(int i){
    return i&~(i-1);
}

int main(){
    cout<<f(INT_MAX)<<endl; 
    cout<<f(INT_MIN)<<endl; 
    cout<<f(4)<<endl; 
    cout<<bitset<32>(INT_MAX)<<endl;
    cout<<bitset<32>(INT_MIN)<<endl;
    cout<<bitset<32>(1)<<endl;
    cout<<bitset<32>(-1)<<endl;
}