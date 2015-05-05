
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

def print_list(root):
    while root:
        print "root val: {0}, next val: {1}, rand val: {2}".format(root.label, "None" if root.next is None else root.next.label, "None" if root.random is None else root.random.label)
        root = root.next


class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if head is None:
            return None
        res = None
        curr = head
        while curr is not None:
            temp = curr.next
            n = RandomListNode(curr.label)
            curr.next = n
            n.next = temp
            curr = temp
        curr = head
        while curr is not None:
            if curr.random is not None:
                curr.next.random = curr.random.next
            else:
                curr.next.random = None
            curr = curr.next.next
        curr = head
        x = head.next
        while curr is not None:
            temp = curr.next.next
            if res is None:
                res = curr.next
            else:
                res.next = curr.next
                res = curr.next 
            curr.next = temp
            curr = temp
        return x 


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
    n = Solution().copyRandomList(n0)
    print "---"
    print_list(n)
