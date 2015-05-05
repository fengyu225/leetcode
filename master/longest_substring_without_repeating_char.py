class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        if len(s)<2:
            return len(s)
        m = [0]*256
        start = end = 0
        res = 0
        while end<len(s):
            if m[ord(s[end])] == 0:
                res = max(res,end-start+1)
                m[ord(s[end])]+=1
                end += 1
                continue
            while True:
                m[ord(s[start])] -= 1
                start += 1
                if s[start-1] == s[end]:
                    break
        return res
                

print Solution().lengthOfLongestSubstring("abcabcbb")
