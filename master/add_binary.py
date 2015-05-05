import itertools

class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        res = ""
        carry = 0
        for chars in itertools.izip_longest(reversed(a),reversed(b)):
            a_num = 0 if chars[0] is None else 0 if chars[0]=='0' else 1
            b_num = 0 if chars[1] is None else 0 if chars[1]=='0' else 1
            x = a_num+b_num+carry
            res = ('0' if x%2==0 else '1' )+res
            carry = x/2
        if carry:
            res = '1'+res
        return res



if __name__ == "__main__":
    print Solution().addBinary("11","1")
