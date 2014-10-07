
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        res = None


def print_list(root):
    while root:
        print "root val: {0}, next val: {1}, rand val: {2}".format(root.label, "None" if root.next is None else root.next.label, "None" if root.random is None else root.random.label)
        root = root.next


if __name__ == "__main__":
    n0 = RandomListNode(0)
    n1 = RandomListNode(1)
    n2 = RandomListNode(2)
    n3 = RandomListNode(3)
    n4 = RandomListNode(4)
    n5 = RandomListNode(5)
    n0.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    n0.random = n3
    n1.random = n1
    n2.random = n4
    n3.random = n5
    n4.random = n2
    print_list(n0)
