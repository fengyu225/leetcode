/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
#include "header.h"

vector<int> diffWaysToCompute(string input){
    int sz = input.length();
    vector<int> res;
    if(sz == 0) return res;
    vector<string> input_arr;
    int l=0, r = 0;
    while(r<sz){
        if(input[r] == '+' || input[r] == '-' || input[r] == '*'){
            input_arr.push_back(input.substr(l, r-l));
            input_arr.push_back(string(1,input[r]));
            l = r+1;
        }
        r++;
    }
    input_arr.push_back(input.substr(l, r-l));
    sz=input_arr.size();
    vector<vector<vector<int> > > arr(sz, vector<vector<int> >(sz, vector<int>()));
    for(int len = 1; len<=sz; len+=2){
        for(int start = 0; start+len<=sz; start+=2){
            if(len == 1) arr[start][start] = vector<int>(1, stoi(input.substr(start, 1))); 
            else{
                vector<int> temp;
                for(int left_len = 1; left_len<len; left_len+=2){
                    vector<int> left = arr[start][start+left_len-1];
                    vector<int> right = arr[start+left_len+1][start+len-1];
                    for(int l_v:left){
                        for(int r_v:right){
                            if(input_arr[start+left_len] == "+") temp.push_back(l_v+r_v);
                            if(input_arr[start+left_len] == "-") temp.push_back(l_v-r_v);
                            if(input_arr[start+left_len] == "*") temp.push_back(l_v*r_v);
                        }
                    }
                }  
                arr[start][start+len-1] = temp;
            }
        }
    } 
    return arr[0][sz-1];
}

int main(){
    vector<string> input = {
        "2*3-4*5",
        "2-1-1"
    };
    for(string s:input){
        cout<<s<<endl;
        vector<int> res = diffWaysToCompute(s);
        print_vector<int>(res);
    }
    return 0;
}