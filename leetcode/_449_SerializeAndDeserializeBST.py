from typing import List, Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        def collectInPreorder(root: Optional[TreeNode], collector: List[int]):
            if root is not None:
                collector.append(root.val)
                collectInPreorder(root.left, collector)
                collectInPreorder(root.right, collector)

        collector = []
        collectInPreorder(root, collector)
        return ','.join(map(str, collector))

    def deserialize(self, data: str) -> Optional[TreeNode]:
        preorder = [int(v) for v in data.split(',') if data != '']

        def construct(p, s, a, b):
            n = len(p)
            if s >= n or p[s] < a or p[s] > b:
                return (s, None)
            li, ln = construct(p, s + 1, a, p[s])
            ri, rn = construct(p, li, p[s], b)

            return (ri, TreeNode(p[s], ln, rn))

        return construct(preorder, 0, float('-inf'), float('inf'))[1]
