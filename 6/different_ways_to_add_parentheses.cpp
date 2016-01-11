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
}

int main(){
    vector<string> input = {
		"(2*(3-(4*5)))",
		"((2*3)-(4*5))",
		"((2*(3-4))*5)",
		"(2*((3-4)*5))",
		"(((2*3)-4)*5)"
    };
    for(string s:input){
        cout<<s<<endl;
        vector<int> res = diffWaysToCompute(s);
        print_vector<int>(res);
    }
    return 0;
}