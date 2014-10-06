
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        res = []
        if root is None:
            return res
        q = [[],[]]
        temp = [root.val]
        curr = 0
        q[curr].append(root)
        while len(q[curr%2])>0:
            n = q[curr%2][0]
            q[curr%2] = q[curr%2][1:]
            if n.left is not None:
                q[(curr+1)%2].append(n.left)
            if n.right is not None:
                q[(curr+1)%2].append(n.right)
            if len(q[curr%2]) == 0:
                res.append(temp)
                temp = []
                curr += 1
        return res


if __name__ == "__main__":
    n3 = Node(3)
    n9 = Node(9)
    n20 = Node(20)
    n15 = Node(15)
    n7 = Node(7)
    n3.left = n9
    n3.right = n20
    n20.left = n15
    n20.right = n7
    print Solution().levelOrder(n3)
