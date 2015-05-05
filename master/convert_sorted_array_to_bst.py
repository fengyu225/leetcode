
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedArrayToBST_helper(self,num,idx,start,end):
        if start>end:
            return None
        m = (start+end)/2
        l = self.sortedArrayToBST_helper(num,idx,start,m-1)
        curr_root = TreeNode(num[m])
        curr_root.left = l
        r = self.sortedArrayToBST_helper(num,idx,m+1,end)
        curr_root.right = r
        return curr_root


    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        if len(num) == 0:
            return None
        return self.sortedArrayToBST_helper(num,0,0,len(num)-1)


if __name__ == "__main__":
    print Solution().sortedArrayToBST([1, 2, 3, 4, 5, 6, 7, 8])
