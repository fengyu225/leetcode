
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def balanced_helper(self,root):
        if root is None:
            return 0
        l = self.balanced_helper(root.left)
        r = self.balanced_helper(root.right)
        if l<0 or r<0 or abs(l-r)>1:
            return -1
        return max(l,r)+1
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        return True if self.balanced_helper(root)>=0 else False


if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)
    n1.left = n2
    n1.right = n5
    n2.left = n3
    n2.right = n4
    n5.right = n6
    print Solution().isBalanced(n1)
