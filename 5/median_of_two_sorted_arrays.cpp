#include "header.h"

int find_k(vector<int>& num1, int l1, int r1, vector<int>& num2, int l2, int r2, int k){
	int sz1 = r1-l1+1;
	int sz2 = r2-l2+1;
	if(sz1>sz2)
		return find_k(num2,l2, r2, num1, l1, r1, k);
	if(sz1==0) return num2[l2+k-1];
	if(k==1) return min(num1[l1], num2[l2]);
	int x = min(k/2, sz1);
	int y = k-x;
	if(num1[l1+x-1] == num2[l2+y-1]) return num1[l1+x-1];
	if(num1[l1+x-1]<num2[l2+y-1])
		return find_k(num1, l1+x, r1, num2, l2, r2, k-x);
	else
		return find_k(num1, l1, r1, num2, l2+y, r2, k-y);
}

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2){
	int x = num1.size()+num2.size();
	if(x==0) return 0;
	if(x%2==0) return (double)(find_k(num1,0, num1.size()-1, num2, 0, num2.size()-1, x/2)+find_k(num1, 0, num1.size()-1,num2,0, num2.size()-1, x/2+1))/2.0;
	else return (double)find_k(num1, 0, num1.size()-1,num2,0, num2.size()-1, x/2+1);
}

int main(){
    int A[] = {2, 3, 4, 5, 6, 7};
    int B[] = {1};
//    int A[] = {1,2};
//    int B[] = {1,2,3};
	vector<int> num1(A,A+sizeof(A)/sizeof(A[0]));
	vector<int> num2(B,B+sizeof(B)/sizeof(B[0]));
    printf("%f\n", findMedianSortedArrays(num1,num2));
    return 0;
}
