
class Solution:
    def gen_helper(self,n,idx,open_n,res,s):
        if open_n<0:
            return
        if idx == n*2:
            if open_n == 0:
                res.append(s[:])
            return
        s += "("
        self.gen_helper(n,idx+1,open_n+1,res,s)
        s = s[:-1]
        if open_n>0:
            s += ")"
            self.gen_helper(n,idx+1,open_n-1,res,s)
            s = s[:-1]

    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        res = []
        s = ""
        self.gen_helper(n,0,0,res,s)
        return res

print Solution().generateParenthesis(3)
