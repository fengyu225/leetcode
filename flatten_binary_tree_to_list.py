
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def in_order(root):
    if root is None:
        return
    in_order(root.left)
    print root.val
    in_order(root.right)

class Solution:
    def flatten_helper(self,root):
        if root is None:
            return None,None
        l_h, l_t = self.flatten_helper(root.left)
        r_h, r_t = self.flatten_helper(root.right)
        new_head = root
        if l_h:
            root.right = l_h
        new_tail = l_t if l_t else root
        if r_h:
            new_tail.right = r_h
        new_tail = r_t if r_t else new_tail
        new_head.left = None
        new_tail.left = None
        return new_head,new_tail

    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if root is None:
            return
        self.flatten_helper(root)

if __name__ == "__main__":
    n1 = TreeNode(1)
    n2 = TreeNode(2)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n6 = TreeNode(6)
    n1.left = n2
    n1.right = n5
    n2.left = n3
    n2.right = n4
    n5.right = n6
    in_order(n1)
    Solution().flatten(n1)
    print "---"
    in_order(n1)
