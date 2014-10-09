class Solution:
    def get_left(self,height):
        left = [0 for i in range(len(height))]
        height.append(0)
        stack = []
        for i in range(0,len(height),1):
            if stack == []:
                stack.append(i)
                continue
            while stack != [] and height[stack[-1]]>=height[i]:
                n = stack.pop()
                left[n] = height[n]*(n+1 if stack == [] else n-stack[-1])
            stack.append(i)
        height.pop()
        return left
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        left = self.get_left(height)
        right = list(reversed(self.get_left(list(reversed(height)))))
        res = 0 
        for i in range(len(height)):
            res = max(res,left[i]+right[i]-height[i])
        return res
    # @param matrix, a list of lists of 1 length string
    # @return an integer
    def maximalRectangle(self, matrix):
        for idx in range(len(matrix)):

matrix = 
    [
            [1,0,1,0,0],
            [0,1,1,1,0],
            [0,1,1,1,0],
            [0,1,1,1,0]
    ]

print Solution().maximalRectangle(matrix)
