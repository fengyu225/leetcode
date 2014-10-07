
class Solution:
    def combinationSum_helper(self,candidates,target,res,s,idx,curr_sum):
        if idx >= len(candidates):
            return
        if curr_sum == target:
            res.append(s[:])
            return
        if curr_sum+candidates[idx]>target:
            return
        self.combinationSum_helper(candidates,target,res,s,idx+1,curr_sum)
        s.append(candidates[idx])
        self.combinationSum_helper(candidates,target,res,s,idx,curr_sum+candidates[idx])
        s.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        res = []
        s = []
        if candidates == []:
            return res
        candidates = sorted(candidates)
        self.combinationSum_helper(candidates,target,res,s,0,0)
        return res

if __name__ == "__main__":
    print Solution().combinationSum([2, 3, 6, 7], 7)
