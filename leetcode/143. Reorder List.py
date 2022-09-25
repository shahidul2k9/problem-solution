from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = slow.next if slow else None

        while fast and fast.next != None:
            slow = slow.next
            fast = fast.next.next

        sentinel = ListNode(-1, None)
        slow.next, slow = None, slow.next
        while slow:
            x = slow
            slow = slow.next
            x.next = sentinel.next
            sentinel.next = x
        slow = sentinel.next

        sentinel.next = None
        cur = sentinel
        while head:
            cur.next, head = head, head.next
            cur = cur.next
            cur.next = slow
            cur = cur.next
            if slow:
                slow = slow.next

        return sentinel.next
