
class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        begin_h = 0
        curr_h = 0
        curr_n = 0
        while curr_h<len(haystack):
            if curr_n == len(needle):
                return haystack[begin_h:]
            if haystack[curr_h] == needle[curr_n]:
                curr_h += 1
                curr_n += 1
            else:
                begin_h += 1
                curr_h = begin_h
                curr_n = 0
        return None if curr_n<len(needle) else haystack[begin_h:]

print Solution().strStr("hello, world", "o, world")
print Solution().strStr("hello, world", "o, word")
print Solution().strStr("NULL", "NOT NULL")
