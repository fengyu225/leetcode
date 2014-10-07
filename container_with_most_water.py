
class Solution:
    # @return an integer
    def maxArea(self, height):
        res = 0
        l,r=0,len(height)-1
        while l<r:
            m = abs(l-r)*min(height[l],height[r])
            res = max(res,m)
            if height[l]<=height[r]:
                l+=1
            else:
                r-=1
        return res


if __name__ == "__main__":
    print Solution().maxArea([9, 8, 7, 6, 5, 7, 10, 13, 9])
