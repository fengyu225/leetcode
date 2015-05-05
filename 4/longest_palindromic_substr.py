"""
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
"""

class Solution:
    def expend(self,s,i,j):
        res = (-1,-1)
        while i>=0 and j<len(s) and s[i] == s[j]:
            res = (i,j) 
            i-=1
            j+=1
        return res
    # @return a string
    def longestPalindrome(self, s):
        res = s[0]
        for i in range(0,len(s),1):
            a,b = self.expend(s,i,i)
            if b-a+1>len(res):
                res = s[a:b+1]
        for i in range(0,len(s)-1,1):
            a,b = self.expend(s,i,i+1)
            if b-a+1>len(res):
                res = s[a:b+1]
        return res

print Solution().longestPalindrome("abacdfgdcaba")
