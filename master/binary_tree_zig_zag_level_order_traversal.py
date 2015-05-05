
class Node(object):
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def zigzagLevelOrder(self, root):
        res = []
        if root is None:
            return res
        left2right = True 
        curr = 0
        qs = [[root],[]]
        temp = []
        while qs[curr%2] != []:
            n = qs[curr%2].pop()
            temp.append(n.val)
            if left2right:
                if n.left:
                    qs[(curr+1)%2].append(n.left)
                if n.right:
                    qs[(curr+1)%2].append(n.right)
            else:
                if n.right:
                    qs[(curr+1)%2].append(n.right)
                if n.left:
                    qs[(curr+1)%2].append(n.left)
            if qs[curr%2] == []:
                res.append(temp)
                left2right = False if left2right else True
                temp = []
                curr += 1
        return res

if __name__ == "__main__":
    n9 = Node(9)
    n3 = Node(3)
    n20 = Node(20)
    n15 = Node(15)
    n7 = Node(7)
    n3.left = n9
    n3.right = n20
    n20.left = n15
    n20.right = n7
    print Solution().zigzagLevelOrder(n3)
