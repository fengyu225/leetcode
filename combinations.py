
class Solution:
    def combine_helper(self,n,k,res,s,idx):
        if len(s) == k:
            res.append(s[:])
            return
        if idx>n:
            return
        self.combine_helper(n,k,res,s,idx+1)
        s.append(idx)
        self.combine_helper(n,k,res,s,idx+1)
        s.pop()

    # @return a list of lists of integers
    def combine(self, n, k):
        res = []
        s = []
        self.combine_helper(n,k,res,s,1)
        return res

if __name__ == "__main__":
    print Solution().combine(4,2)
