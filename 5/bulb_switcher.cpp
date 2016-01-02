/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.

*/

#include "header.h"

/*
https://leetcode.com/discuss/75014/math-solution
A bulb ends up on iff it is switched an odd number of times.

Call them bulb 1 to bulb n. Bulb i is switched in round d if and only if d divides i. So bulb i ends up on if and only if it has an odd number of divisors.

Divisors come in pairs, like i=12 has divisors 1 and 12, 2 and 6, and 3 and 4. Except when i is a square, like 36 has divisors 1 and 36, 2 and 18, 3 and 12, 4 and 9, and double divisor 6. So bulb i ends up on if and only if i is a square.

So just count the square numbers.
*/

int bulbSwitch(int n) {
    return sqrt(n);
}

//off off off off off off off
//on on on on on on on
//on off on off on off on
//on off off off on on on 

//on off off off on on off 
//on off off off on on on 
//on off off off on on off 
//on off off off on on on 
int main(){
    cout<<bulbSwitch(1)<<endl;
    cout<<bulbSwitch(3)<<endl;
    cout<<bulbSwitch(4)<<endl;
    cout<<bulbSwitch(5)<<endl;
    cout<<bulbSwitch(6)<<endl;
    cout<<bulbSwitch(7)<<endl;
    return 0;
}