class Solution:
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        if len(s1) == 0:
            return s2 == s3
        if len(s2) == 0:
            return s1 == s3
        s1_len = len(s1)
        s2_len = len(s2)
        s3_len = len(s3)
        if s1_len+s2_len != s3_len:
            return False
        arr = [[False for i in range(s3_len+1)] for j in range(s1_len+1)]
        arr[0][1] = True if s2[0]==s3[0] else False
        arr[1][1] = True if s1[0]==s3[0] else False
        for i in range(2,s3_len+1,1):
            for j in range(0,min(i,s1_len)+1,1):
                if i-j>s2_len:
                    continue
                if j>0 and s3[i-1]==s1[j-1] and arr[j-1][i-1]:
                    arr[j][i] = True
                elif i!=j and s3[i-1]==s2[i-j-1] and arr[j][i-1]:
                    arr[j][i] = True
        return arr[s1_len][s3_len]

print Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac")
print Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc")
