
class Solution:
    def valid(self,s,i):
        return s[i]=='1' or s[i]=='2' and int(s[i+1])<7
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        if len(s) == 0:
            return 0
        arr = [0 for i in range(len(s))]
        arr[0] = 0 if s[0]=='0' else 1
        if len(s) == 1:
            return arr[0]
        arr[1] = (1 if self.valid(s,0) else 0)+(arr[0] if s[1] != '0' else 0)
        for i in range(2,len(s),1):
            arr[i] += (arr[i-2] if self.valid(s,i-1) else 0)
            arr[i] += (arr[i-1] if s[i] != '0' else 0)
        return arr[len(s)-1]


if __name__ == "__main__":
    print Solution().numDecodings("01")
    print Solution().numDecodings("00")
    print Solution().numDecodings("10")
    print Solution().numDecodings("27")
