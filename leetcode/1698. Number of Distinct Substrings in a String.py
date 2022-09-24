class Node:
    def __init__(self):
        self.child = [None] * 26
class Solution:
    def countDistinct(self, s: str) -> int:
        n = len(s)
        root = Node()
        words = 0
        for i in range(n):
            node = root
            for j in range(i, n):
                ch = s[j]
                index = ord(ch) - ord('a')
                if not node.child[index]:
                    node.child[index] = Node()
                    words += 1
                node = node.child[index]
        return words