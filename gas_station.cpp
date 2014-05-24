/*
 *  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 *  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 *  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 *  Note:
 *  The solution is guaranteed to be unique. 
 */

#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    return 0;
}

int main(){
    int gas_arr[] = {0, 3, 0};
    int cost_arr[] = {1, 1, 1}; 
    vector<int> gas(gas_arr,gas_arr+sizeof(gas_arr)/sizeof(gas_arr[0]));
    vector<int> cost(cost_arr,cost_arr+sizeof(cost_arr)/sizeof(cost_arr[0]));
    printf("%d %d\n", gas.size(), cost.size());
    return 0;
}
