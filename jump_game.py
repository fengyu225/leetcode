class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if len(A) == 0:
            return True
        start = end = 0
        while end<len(A)-1:
            new_end = end
            for i in range(start,end+1,1):
                new_end = max(i+A[i],new_end)
            if new_end == end:
                return False
            start = end+1
            end = new_end
        return True


print Solution().canJump([2, 3, 1, 1, 4])
print Solution().canJump([3, 2, 1, 0, 4])
