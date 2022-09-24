import collections
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.dq = collections.deque()
        self.collect_leafs(root)

    def collect_leafs(self, root):
        level_dq = collections.deque([root])
        while level_dq:
            u = level_dq.popleft()
            if not u.left or not u.right:
                self.dq.append(u)
            for v in [u.left, u.right]:
                if v:
                    level_dq.append(v)

    def insert(self, val: int) -> int:
        sub_root = self.dq.popleft()
        child = TreeNode(val)
        if not sub_root.left:
            sub_root.left = child
            self.dq.appendleft(sub_root)
        else:
            sub_root.right = child
        self.dq.append(child)
        return sub_root.val

    def get_root(self) -> Optional[TreeNode]:
        return self.root

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()