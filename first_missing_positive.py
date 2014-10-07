
class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        n = len(A)
        if n == 0:
            return 1
        for i in range(0,len(A),1):
            while A[i]>=0 and A[i]<n and A[i] != i:
                temp = A[i]
                if A[temp] == A[i]:
                    break
                A[i] = A[temp]
                A[temp] = temp
        for i in range(1,len(A),1):
            if A[i] != i:
                return i
        if A[0] == n:
            return n+1
        else:
            return n
            

print Solution().firstMissingPositive([3, 4, -1, 1])
