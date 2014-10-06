
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):


if __name__ == "__main__":
    n3 = Node(3)
    n9 = Node(9)
    n20 = Node(20)
    n15 = Node(15)
    n7 = Node(7)
    n3.left = n9
    n2.right = n20
    n20.left = n15
    n20.right = n7
    print Solution().levelOrder(n3)
