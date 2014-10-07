import pdb

class Solution:
    def comb_helper(self,candidates,target,res,s,idx,curr_sum):
        if curr_sum == target:
            res.append(s[:])
            return
        if idx>=len(candidates):
            return
        if candidates[idx]+curr_sum > target:
            return
        temp = idx
        while idx+1<len(candidates) and candidates[idx+1] == candidates[idx]:
            idx+=1
        self.comb_helper(candidates,target,res,s,idx+1,curr_sum)
        s.append(candidates[temp])
        self.comb_helper(candidates,target,res,s,temp+1,curr_sum+candidates[temp])
        s.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        if candidates == []:
            return []
        res = []
        s = []
        candidates = sorted(candidates)
        self.comb_helper(candidates,target,res,s,0,0)
        return res

if __name__ == "__main__":
    #print Solution().combinationSum2([10, 1, 2, 7, 6, 1, 5], 8)
    print Solution().combinationSum2([1], 1)
