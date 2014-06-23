#include "header.h"

int max_rectangle(vector<int>& v){
    stack<int> s;
    if(v.size() == 0) return 0;
    v.push_back(0);
    int result = 0;
    for(int i=0; i<v.size(); i++){
        if(s.empty() || v[i]>v[s.top()]) s.push(i);
        else{
            int top = s.top();
            s.pop();
            result = max(result,v[top]*(s.empty()?i:i-1-s.top()));
            i--;
        }
    }
    return result;
}


int maximalRectangle(vector<vector<char> > &matrix) {
    vector<vector<int> > v;
    for(int i=0; i<matrix.size();i++){
        vector<int> v_curr;
        for(int j=0;j<matrix[i].size();j++){
            if(v.empty())
                v_curr.push_back(matrix[i][j]-'0');
            else{
                v_curr.push_back((matrix[i][j]-'0')==1?v.back()[j]+1:0);
            }
        }
        v.push_back(v_curr);
    }
    int result = 0;
    for(int i=0;i<v.size();i++){
        result = max(result,max_rectangle(v[i]));
    }
    return result;
}

int main(){
    char arr0[] = "10100";
    char arr1[] = "01110";
    char arr2[] = "01110";
    char arr3[] = "01110";
    vector<char> v0(arr0,arr0+sizeof(arr0)/sizeof(arr0[0])-1);
    vector<char> v1(arr1,arr1+sizeof(arr1)/sizeof(arr1[1])-1);
    vector<char> v2(arr2,arr2+sizeof(arr2)/sizeof(arr2[2])-1);
    vector<char> v3(arr3,arr3+sizeof(arr3)/sizeof(arr3[3])-1);
    vector<vector<char> > matrix;
    matrix.push_back(v0);
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    int res = maximalRectangle(matrix);
    printf("%d\n", res);
    return 0;
}
