"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""


class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        def flaten(st):
            cur = st
            cur_prev = cur
            while cur:
                if cur.child:
                    child_st, child_en = flaten(cur.child)
                    cur.child = None

                    child_en.next = cur.next
                    if cur.next != None:
                        cur.next.prev = child_en

                    cur.next, child_st.prev = child_st, cur
                    cur = child_en
                cur_prev = cur
                cur = cur.next
            return st, cur_prev

        return flaten(head)[0]


