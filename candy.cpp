/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include "header.h"

int candy(vector<int> &ratings){
    int sz = ratings.size();
    if(sz == 0) return 0;
    vector<int> left(sz,1);
    vector<int> right(sz,1);
    for(int i=1; i<sz; i++)
        if(ratings[i]>ratings[i-1] && left[i]<=left[i-1]) left[i] = left[i-1]+1;
    for(int i=sz-2; i>=0; i--)
        if(ratings[i]>ratings[i+1] && right[i]<=right[i+1]) right[i] = right[i+1]+1;
    int res = 0;
    for(int i=0; i<sz; i++) res += max(left[i],right[i]);
    return res;
}

int main(){
    //int rating_arr[] = {5, 4, 3, 6, 4, 1, 2};
    int rating_arr[] = {4, 2, 3, 4, 1};
    vector<int> ratings(rating_arr, rating_arr+sizeof(rating_arr)/sizeof(rating_arr[0]));
    printf("%d\n", candy(ratings));
    return 0;
}
