
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxPathSum_helper(self, root):
        if root is None:
            return (0,-1*2147483648)
        l = self.maxPathSum_helper(root.left)
        r = self.maxPathSum_helper(root.right)
        m = max(l[1],r[1],l[0]+root.val,r[0]+root.val,l[0]+r[0]+root.val,root.val)
        return (max(root.val,max(l[0],r[0])+root.val),m)
    
    def maxPathSum(self,root):
        return self.maxPathSum_helper(root)[1] if root is not None else 0

if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n1.left = n2
    n1.right = n3
    print Solution().maxPathSum(n1)
