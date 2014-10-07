
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):

def print_list(root):
    while root:
        print "root val: {0}, next val: {1}, rand val: {2}".format(root.val, "None" if root.next is None else root.next.val, "None" if root.random is None else root.random.val)
        root = root.next


if __name__ == "__main__":

