
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
        stack = [root]
        while len(stack)>0:
            while stack[-1].left is not None:
                stack.append(stack[-1].left)
            while len(stack)>0 and stack[-1].right is None:
                res.append(stack[-1].val)
                stack.pop()
            if not len(stack)==0:
                res.append(stack[-1].val)
                n = stack.pop()
                stack.append(n.right)
        return res


if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n1.right = n2
    n2.left = n3
    print Solution().inorderTraversal(n1)
