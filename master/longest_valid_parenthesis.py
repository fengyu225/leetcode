class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        if len(s)<2:
            return 0
        stack = []
        x = -1
        res = 0
        for idx,c in enumerate(s):
            if c == "(":
                stack.append(idx)
                continue
            if stack == []:
                x = idx
                continue
            t = stack.pop()
            if stack == []:
                res = max(res,idx-x)
            else:
                res = max(res,idx-stack[-1])
        return res

print Solution().longestValidParentheses(")()())")
