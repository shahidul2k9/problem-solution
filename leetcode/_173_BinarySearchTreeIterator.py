class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class BSTIterator(object):
    def __init__(self, root):
        self.root = root
        self.stack = []
        self.inorder_left(root)
    def next(self):
        top = self.stack.pop()
        self.inorder_left(top.right)
        return top.val

    def hasNext(self):
        return len(self.stack) > 0

    def inorder_left(self, root):
        while root:
            self.stack.append(root)
            root = root.left