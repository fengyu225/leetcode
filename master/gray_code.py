
class Solution:
    # @return a list of integers
    def grayCode(self, n):
        res = []
        for i in range(0,2**n,1):
            res.append((i>>1)^i)
        return res

print Solution().grayCode(2)
