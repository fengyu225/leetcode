# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    def __repr__(self):
        return str(self.val)

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        slow = fast = head
        if head is None or head.next is None:
            return None 
        while True:
            slow = slow.next
            fast = fast.next
            if not fast:
                return None 
            fast = fast.next
            if not fast:
                return None 
            if slow == fast:
                break
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow


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
    print Solution().detectCycle(n1)
