from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd = odd_sentinel = ListNode()
        even = even_sentinel = ListNode()
        while head:
            odd.next, head = head, head.next
            odd = odd.next
            if head:
                even.next, head = head, head.next
                even = even.next
        odd.next, even.next = even_sentinel.next, None
        return odd_sentinel.next




