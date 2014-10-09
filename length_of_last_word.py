class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        seen_space = False
        start = 0
        curr = 0
        res = 0
        while curr<len(s):
            if s[curr] != ' ':
                if seen_space:
                    start = curr
                    seen_space = False
                curr += 1
                res = curr-start
                continue
            if not seen_space:
                seen_space = True
            curr += 1
        return res

print Solution().lengthOfLastWord("HELLO WORLD  ")
