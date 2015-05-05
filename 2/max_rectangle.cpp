#include "header.h"

void find_left(vector<int>& h, vector<int>& left){
    stack<int> stack;
    h.push_back(0);
    for(int i=0; i<h.size(); i++){
        if(stack.empty() || h[stack.top()]<h[i]){
            stack.push(i);
            continue;
        }
        while(!stack.empty() && h[stack.top()]>=h[i]){
            int x = stack.top();
            stack.pop();
            left[x] = stack.empty()?h[x]*(x+1):h[x]*(x-stack.top());
        }
        stack.push(i);
    }
//    for(int i=0; i<left.size(); i++)
//        cout<<left[i]<<" ";
//    cout<<endl;
    h.pop_back();
}

int largestRectangleArea(vector<int> &h) {   
    vector<int> left(h.size(),0);
    vector<int> right(h.size(),0);
    find_left(h,left);
    std::reverse(h.begin(), h.end());
    find_left(h,right);
    std::reverse(right.begin(), right.end());
    std::reverse(h.begin(), h.end());
    int res = 0;
    for(int i=0; i<h.size(); i++)
        res = std::max(res,(left[i]+right[i]-h[i]));
    return res;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    vector<vector<int> > vs;
    for(int i=0; i<matrix.size(); i++){
        vector<int> v;
        for(int j=0; j<matrix[i].size(); j++){
            if(vs.empty())
                v.push_back(matrix[i][j]-'0');
            else{
                v.push_back(matrix[i][j]=='0'?0:vs.back()[j]+1);
            }
        }
        vs.push_back(v);
    }
    int res = 0;
    for(int i=0; i<vs.size(); i++)
        res = std::max(largestRectangleArea(vs[i]), res);
    return res;
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
