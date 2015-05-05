"""
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
"""

class Solution:
    def find_k(self,A,a_st,a_end,B,b_st,b_end,k):
        if a_end-a_st>b_end-b_st:
            return self.find_k(B,b_st,b_end,A,a_st,a_end,k)
        if a_st > a_end:
            return B[b_st+k-1]
        if k == 1:
            return min(A[a_st], B[b_st])
        a_sz = a_end-a_st+1
        b_sz = b_end-b_st+1
        a_m = min(a_sz,k/2)
#        a_m = int(float(a_sz)/float(a_sz+b_sz)*k)
        b_m = k-a_m
        a_idx = a_st+a_m-1
        b_idx = b_st+b_m-1
        if A[a_idx] == B[b_idx]:
            return A[a_idx]
        elif A[a_idx]<B[b_idx]:
            return self.find_k(A,a_idx+1,a_end,B,b_st,b_end,k-(a_idx-a_st+1))
        else:
            return self.find_k(A,a_st,a_end,B,b_idx+1,b_end,k-(b_idx-b_st+1))

    # @return a float
    def findMedianSortedArrays(self, A, B):
        a_sz = len(A)
        b_sz = len(B)
        if (a_sz+b_sz)%2 == 1:
            return float(self.find_k(A,0,a_sz-1,B,0,b_sz-1,(a_sz+b_sz+1)/2))
        else:
            return 0.5*float(self.find_k(A,0,a_sz-1,B,0,b_sz-1,(a_sz+b_sz)/2)+self.find_k(A,0,a_sz-1,B,0,b_sz-1,(a_sz+b_sz)/2+1)) 


#print Solution().findMedianSortedArrays([2, 3, 4, 5, 6, 7], [1, 2])
#print Solution().findMedianSortedArrays([1, 1], [1, 2])
print Solution().find_k([1, 1], 0, 1, [1, 2], 0, 1, 3)
#print Solution().find_k([1, 1], 0, 1, [1, 2], 0, 1, 3)
