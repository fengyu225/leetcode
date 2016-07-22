/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/

#include "header.h"

bool canWin(string s) {
    int sz = s.length();
    for(int i=0; i<sz-1; i++){
        if(s[i] == '+' && s[i+1] == '+'){
            string temp = s;
            temp[i] = '-';
            temp[i+1] = '-';
            bool res = canWin(temp);
            if(!res) return true;
        }
    }
    return false;
}

int main(){
    cout<<canWin("++++")<<endl;
    return 0;
}