class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if len(A) == 0:
            return 0
        res = 0
        start = end = 0
        if len(A) == 0:
            return 0
        while end<len(A)-1:
            new_end = end
            for i in range(start,end+1,1):
                new_end = max(i+A[i],new_end)
            if new_end >= len(A)-1:
                return res+1
            res += 1
            start = end+1
            end = new_end


print Solution().jump([2, 3, 1, 1, 4])
