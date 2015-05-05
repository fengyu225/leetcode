
class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        sign = (dividend<0 and divisor<0) or (dividend>0 and divisor>0)
        res = 0
        dividend = dividend*(1 if dividend>=0 else -1)
        divisor = divisor*(1 if divisor>=0 else -1)
        if dividend<divisor:
            return 0
        for i in range(31,-1,-1):
            if(dividend>>i >= divisor):
                res += 1<<i
                dividend -= (divisor<<i)
        return (1 if sign else -1)*res

print Solution().divide(1,0)
