class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ""
        res = ""
        i = 1
        while True:
            if i>len(strs[0]):
                return res
            c = strs[0][i-1]
            for x in range(1,len(strs),1):
                if len(strs[x])<i or strs[x][i-1] != c:
                    return res
            res += c
            i += 1
        return res

if __name__ == "__main__":
    print Solution().longestCommonPrefix(["abcd", "abce", "abc", "ab"])
