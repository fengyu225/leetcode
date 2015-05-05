"""
Determine whether an integer is a palindrome. Do this without extra space.
"""

class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x<0:
            return False
        l,r=1,1
        while 10*l<=x:
            l *= 10
        while l>r:
            a=(x/l)%10
            b=(x/r)%10
            if a!=b:
                return False
            l/=10
            r*=10
        return True

print Solution().isPalindrome(101)
print Solution().isPalindrome(1)
print Solution().isPalindrome(1211)
