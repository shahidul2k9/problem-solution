# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class ListNode:
    pass


class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sorted_head = ListNode(float('-inf'), None)
        next = head
        while next:
            node = next
            next = next.next
            node.next = None
            cur = sorted_head
            while cur.next is not None and cur.next.val < node.val:
                cur = cur.next
            cur.next, node.next = node, cur.next
        return sorted_head.next
