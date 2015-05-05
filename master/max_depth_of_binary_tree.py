# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def max_helper(self,root):
        if root is None:
            return 0
        return max(self.max_helper(root.left), self.max_helper(root.right))+1
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if root is None:
            return 0
        return self.max_helper(root)

n0 = TreeNode(0)
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n0.left = n1
n0.right = n2
n1.left = n3
n1.right = n4
n4.left = n5

print Solution().maxDepth(n0)
