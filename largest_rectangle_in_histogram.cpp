#include "header.h"

//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

int max(int a,int b){
    return a>b?a:b;
}

int largestRectangleArea(vector<int> &h) {   
     stack<int> S;  
     h.push_back(0);  
     int sum = 0;  
     for (int i = 0; i < h.size(); i++) {   
          if (S.empty() || h[i] > h[S.top()]) S.push(i);  
          else {   
               int tmp = S.top();  
               S.pop();  
               cout<<"i: "<<i<<endl;
               cout<<"S.empty: "<<S.empty()<<" ";
               if(!S.empty()) cout<<"S.top: "<<S.top()<<" ";
                sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));  
                cout<<"sum: "<<sum<<endl;
                i--;  
           }
     }
     return sum;  
}  

int main(){
    int height[] = {6, 2, 5, 4, 5, 1, 6};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
