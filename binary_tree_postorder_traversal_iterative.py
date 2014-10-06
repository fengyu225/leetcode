
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        res = []
        if root is None:
            return res
        stack = []
        pre = None
        curr = root
        stack.append(curr)
        while stack != []:
            curr = stack[-1] 
            if pre is None or pre.left == curr or pre.right == curr:
                if curr.left:
                    stack.append(curr.left)
                elif curr.right:
                    stack.append(curr.right)
                else:
                    res.append(curr.val)
                    stack.pop()
            elif curr.left == pre:
                if curr.right:
                    stack.append(curr.right)
                else:
                    res.append(curr.val)
                    stack.pop()
            elif curr.right == pre:
                res.append(curr.val)
                stack.pop()
            pre=curr
        return res


if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n1.right = n2
    n2.left = n3
    print Solution().postorderTraversal(n1)
