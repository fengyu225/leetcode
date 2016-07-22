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

vector<int> search(vector<string>& input, int start, int end){
    vector<int> res;
    if(start == end){
        res.push_back(stoi(input[start]));
        return res;
    }
    for(int i=start+1; i<end; i+=2){
        vector<int> x = search(input, start, i-1);
        vector<int> y = search(input, i+1, end);
        for(int a=0; a<x.size(); a++)
            for(int b=0; b<y.size(); b++){
                if(input[i] == "+") res.push_back(x[a]+y[b]);
                if(input[i] == "-") res.push_back(x[a]-y[b]);
                if(input[i] == "*") res.push_back(x[a]*y[b]);
            }
    }
    return res;
}

vector<int> diffWaysToCompute(string input){
    vector<int> res;
    int sz = input.length();
    if(sz == 0) return res;
    vector<string> input_arr;
    int curr = 1, head = 0;
    while(curr<sz){
        if(input[curr] == '+' || input[curr] == '-' || input[curr] == '*'){
            input_arr.push_back(input.substr(head, curr-head));
            input_arr.push_back(input.substr(curr, 1));
            curr++;
            head = curr;
        }
        else curr++;
    }
    input_arr.push_back(input.substr(head, curr-head));
    for(string x:input_arr) cout<<x<<", ";
    cout<<endl;
    return search(input_arr, 0, input_arr.size()-1);
}

//vector<int> diffWaysToCompute(string input){
//    vector<int> res;
//    int sz = input.length();
//    if(sz == 0) return res;
//    vector<string> input_arr;
//    int curr = 1, head = 0;
//    while(curr<sz){
//        if(input[curr] == '+' || input[curr] == '-' || input[curr] == '*'){
//            input_arr.push_back(input.substr(head, curr-head));
//            input_arr.push_back(input.substr(curr, 1));
//            curr++;
//            head = curr;
//        }
//        else curr++;
//    }
//    input_arr.push_back(input.substr(head, curr-head));
//    sz = input_arr.size();
//    vector<vector<vector<int> > > table(sz, vector<vector<int> >(sz, vector<int>()));
//    for(int len=1; len<=sz; len+=2){
//        for(int start = 0; start+len-1<sz; start+=2){
//            vector<int> temp;
//            if(len == 1){
//                temp.push_back(stoi(input_arr[start]));
//                table[start][start+len-1] = temp;
//            }
//            else{
//                for(int l_len = 1; l_len<len; l_len+=2){
//                    vector<int> left = table[start][start+l_len-1];
//                    vector<int> right = table[start+l_len+1][start+len-1];
//                    for(int l_idx = 0; l_idx<left.size(); l_idx++){
//                        for(int r_idx=0; r_idx<right.size(); r_idx++){
//                            if(input_arr[start+l_len] == "+") temp.push_back(left[l_idx]+right[r_idx]);
//                            if(input_arr[start+l_len] == "-") temp.push_back(left[l_idx]-right[r_idx]);
//                            if(input_arr[start+l_len] == "*") temp.push_back(left[l_idx]*right[r_idx]);
//                        }
//                    }
//                } 
//            }
//            table[start][start+len-1] = temp;
//        }   
//    }
//    return table[0][input_arr.size()-1];
//}

int main(){
    vector<int> res = diffWaysToCompute("2*3-4*5");
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}