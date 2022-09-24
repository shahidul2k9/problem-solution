import random


class Node:
    def __init__(self, val: int, right=None, down=None):
        self.val = val
        self.right = right
        self.down = down

    def __repr__(self):
        node = self
        levels = []
        while node:
            levels.append([])
            cur = node
            while cur:
                levels[-1].append(cur.val)
                cur = cur.right
            node = node.down
        return str(levels)


class Skiplist:

    def __init__(self):
        self.head = Node(-1)

    def search(self, target: int) -> bool:
        # print(self.head)
        node = self.head
        while node:
            while node.right and node.right.val < target:
                node = node.right
            if node.right and node.right.val == target:
                return True
            else:
                node = node.down
        return False

    def add(self, num: int) -> None:
        # print(self.head)

        path = []
        node = self.head
        while node:
            while node.right and node.right.val < num:
                node = node.right
            path.append(node)
            node = node.down
        insert = True
        down = None
        while insert and path:
            node = path.pop()
            down = node.right = Node(num, node.right, down)
            insert = random.getrandbits(1) == 1
        if insert:
            self.head = Node(-1, None, self.head)

    def erase(self, num: int) -> bool:
        erased = False
        node = self.head
        while node:
            while node.right and node.right.val < num:
                node = node.right
            if node.right and node.right.val == num:
                node.right = node.right.right
                erased = True
            node = node.down
        return erased

# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)