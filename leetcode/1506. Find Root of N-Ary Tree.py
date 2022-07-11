from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        root_value = 0
        for node in tree:
            root_value ^= node.val
            for child in node.children:
                root_value ^= child.val
        for node in tree:
            if node.val == root_value:
                return node
        return None