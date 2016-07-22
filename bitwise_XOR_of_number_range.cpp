/*
http://stackoverflow.com/questions/10670379/find-xor-of-all-numbers-in-a-given-range

long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}

This is a pretty clever solution -- it exploits the fact that there is a pattern of results in the running XORs. The f() function calculates the XOR total run from [0, a]. Take a look at this table for 4-bit numbers:

0000 <- 0  [a]
0001 <- 1  [1]
0010 <- 3  [a+1]
0011 <- 0  [0]
0100 <- 4  [a]
0101 <- 1  [1]
0110 <- 7  [a+1]
0111 <- 0  [0]
1000 <- 8  [a]
1001 <- 1  [1]
1010 <- 11 [a+1]
1011 <- 0  [0]
1100 <- 12 [a]
1101 <- 1  [1]
1110 <- 15 [a+1]
1111 <- 0  [0]
Where the first column is the binary representation and then the decimal result and its relation to its index (a) into the XOR list. This happens because all the upper bits cancel and the lowest two bits cycle every 4. So, that's how to arrive at that little lookup table.

Now, consider for a general range of [a,b]. We can use f() to find the XOR for [0,a-1] and [0,b]. Since any value XOR'd with itself is zero, the f(a-1) just cancels out all the values in the XOR run less than a, leaving you with the XOR of the range [a,b].
*/

#include "header.h"

int rangeBitwiseXor(int m, int n){
    int res = 0;
    for(int i=0; i<=30; i++){
        unsigned int n_1 = (unsigned int)n/(unsigned int)(1<<(i+1));
        n_1 *= (unsigned int)(1<<i);
        unsigned int x = (unsigned int)n/(unsigned int)(1<<(i+1))*(unsigned int)(1<<(i+1));
        x = x==0?-1:x-1;
        int temp = ((unsigned int)n-x)-(1<<i);
        temp = temp<0?0:temp;
        n_1 += temp;

        unsigned int m_1 = (unsigned int)m/(unsigned int)(1<<(i+1));
        m_1 *= (unsigned int)(1<<i);
        x = (unsigned int)m/(unsigned int)(1<<(i+1))*(unsigned int)(1<<(i+1));
        x = x==0?-1:x-1;
        temp = ((unsigned int)m-x)-(1<<i)-1;
        temp = temp<0?0:temp;
        m_1 += temp;

        res |= (n_1-m_1)%2==0?0:(1<<i);
    }
    return res;
}

int main(){
    cout<<rangeBitwiseXor(5,7)<<endl;
    return 0;
}