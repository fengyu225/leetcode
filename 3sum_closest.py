import sys
class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        num = sorted(num)
        res = sys.maxsize
        diff = sys.maxsize
        if len(num)<3:
            return res
        for i in range(0,len(num)-2,1):
            j,k=i+1,len(num)-1
            while j<k:
                if num[i]+num[j]+num[k] == target:
                    return target
                s = num[i]+num[j]+num[k]
                if abs(s-target)<diff:
                    print i,j,k
                    res = s
                    diff = abs(s-target)
                if s<target:
                    j+=1
                else:
                    k-=1
        return res



if __name__ == "__main__":
    print Solution().threeSumClosest([-1, 2, 1, -4], 1)
