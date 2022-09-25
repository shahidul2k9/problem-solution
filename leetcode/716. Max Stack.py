from heapq import heappop, heappush


class Item:
    def __init__(self, val: int, id: int):
        self.val = val
        self.id = id

    def __lt__(self, other) -> bool:
        return not self.lt(other)

    def lt(self, other) -> bool:
        if self.val != other.val:
            return self.val < other.val
        else:
            return self.id <= other.id


class MaxStack:

    def __init__(self):
        self.id = 0
        self.stack = []
        self.max_pq = []
        self.deleted_ids = set()

    def push(self, x: int) -> None:
        item = Item(x, self.id)
        self.stack.append(item)
        heappush(self.max_pq, item)
        self.id += 1

    def pop(self) -> int:
        self.clean_tops()
        top = self.stack.pop()
        self.deleted_ids.add(top.id)
        return top.val

    def top(self) -> int:
        self.clean_tops()
        return self.stack[-1].val

    def peekMax(self) -> int:
        self.clean_tops()
        return self.max_pq[0].val

    def popMax(self) -> int:
        self.clean_tops()
        top = heappop(self.max_pq)
        self.deleted_ids.add(top.id)
        return top.val

    def clean_tops(self):
        while self.stack and self.stack[-1].id in self.deleted_ids:
            self.stack.pop()
        while self.max_pq and self.max_pq[0].id in self.deleted_ids:
            heappop(self.max_pq)

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()