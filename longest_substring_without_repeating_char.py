"""
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
"""

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        m = [0 for i in range(256)]
        l,r=0,0
        res = 0
        while r<len(s):
            c = ord(s[r])
            if m[c] == 0:
                m[c] += 1
                r += 1
                res = max(r-l, res)
            else:
                while True:
                    m[ord(s[l])]-=1
                    l+=1
                    if s[l-1] == s[r]:
                        break
        return res


#print Solution().lengthOfLongestSubstring("abcabcbb")
print Solution().lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco")
