# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def print_list(n):
    while n:
        print n.val
        n = n.next

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        if head is None or head.next is None:
            return head
        res = None
        curr = head
        while curr:
            temp = curr.next
            curr.next = None
            if res is None:
                res = curr
            elif curr.val<=res.val:
                curr.next = res
                res = curr
            else:
                pre = res 
                next = res.next
                while next:
                    if curr.val<=next.val:
                        break
                    pre = next
                    next = next.next
                pre.next = curr
                curr.next = next
            curr = temp
        return res


if __name__ == "__main__":
#    n1 = ListNode(1)
#    n2 = ListNode(2)
#    n3 = ListNode(3)
#    n4 = ListNode(4)
#    n5 = ListNode(5)
    n1 = ListNode(0)
    n2 = ListNode(0)
    n3 = ListNode(0)
    n4 = ListNode(0)
    n5 = ListNode(0)
    n5.next = n4
    n4.next = n3
    n3.next = n2
    n2.next = n1
    print_list(n5)
    print "---"
    n = Solution().insertionSortList(n5)
    print_list(n)
