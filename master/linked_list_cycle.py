# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        slow = fast = head
        if head is None or head.next is None:
            return False
        while True:
            slow = slow.next
            fast = fast.next
            if not fast:
                return False
            fast = fast.next
            if not fast:
                return False
            if slow == fast:
                return True


if __name__ == "__main__":
    n1 = ListNode(1)    
    n2 = ListNode(2)    
    n3 = ListNode(3)    
    n4 = ListNode(4)    
    n5 = ListNode(5)    
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n2
    print Solution().hasCycle(n1)
