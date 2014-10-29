"""
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
"""

class Solution:
    def match(self,s,s_st,s_end,p,p_st,p_end):
        if p_st > p_end:
            return s_st>s_end
        if p_st == p_end:
            return s_st == s_end and (p[p_st] == "." or s[s_st] == p[p_st])
        if p[p_st+1] != "*":
            return ((p[p_st] == "." and s_st<=s_end) or (p[p_st] == s[s_st])) and self.match(s,s_st+1,s_end,p,p_st+1,p_end)
        while 
            
    # @return a boolean
    def isMatch(self, s, p):
        return self.match(s,0,len(s)-1,p,0,len(p)-1) 
