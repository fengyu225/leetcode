/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/

#include "header.h"

bool knows(int a, int b){
    vector<vector<bool> > arr = {
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    return arr[a][b];
}

class Solution {
public:
//    int findCelebrity(int n) {
//        if(n == 0) return -1;
//        if(n == 1) return 0;
//        int curr = 0, next = 1;
//        while(next<n){
//            if(knows(curr,next)) curr = next++;
//            else next++;
//        }
//        for(int i=0; i<n; i++) if(curr != i && (knows(curr, i) || !knows(i, curr))) return -1;
//        return curr;
//    }
    int findCelebrity(int n) {
        if(n<2) return n?0:-1;
        int curr = 0, next = 1;
        for(;next<n;next++) if(knows(curr,next)) curr = next;
        for(int i=0; i<n; i++) if(curr != i && (knows(curr, i) || !knows(i, curr))) return -1;
        return curr;
    }
};

int main(){
    Solution s;
    cout<<s.findCelebrity(3)<<endl;
    return 0;
}