class Solution:
    def expand(self,s,i,j):
        l,r = i,j
        while l>=0 and r<len(s):
            if s[l] == s[r]:
                l-=1
                r+=1
            else:
                break
        return s[l+1:r]
    # @return a string
    def longestPalindrome(self, s):
        if len(s)<2:
            return s
        s_len = len(s)
        res = s[:1]
        for i in range(0,s_len,1):
            temp_str = self.expand(s,i,i)
            if len(temp_str)>len(res):
                res = temp_str
        for i in range(0,s_len-1,1):
            temp_str = self.expand(s,i,i+1)
            if len(temp_str)>len(res):
                res = temp_str
        return res

print Solution().longestPalindrome("abacdfgdcaba")
