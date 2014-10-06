
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        res = []
        if root is None:
            return res
        curr = root
        while curr is not None:
            if curr.left is None:
                res.append(curr.val)
                curr = curr.right
                continue
            l = curr.left
            while l.right is not None and l.right != curr:
                l = l.right
            if l.right == curr:
                res.append(curr.val)
                curr = curr.right
            else:
                l.right = curr
                curr = curr.left
        return res

if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n1.right = n2
    n2.left = n3
    print Solution().inorderTraversal(n1)
