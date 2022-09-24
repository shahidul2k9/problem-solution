import collections
from heapq import heappush, heappop


class Element:
    def __init__(self, val: int, count: int, time: int):
        self.val = val
        self.count = count
        self.time = time

    def __lt__(self, other) -> bool:
        return not self.less_cmp(other)

    def less_cmp(self, other) -> bool:
        if self.count != other.count:
            return self.count < other.count
        return self.time < other.time

    def __repr__(self):
        return ','.join(list(map(str, [self.count, self.val, self.time])))


class FreqStack:

    def __init__(self):
        self.count_map = collections.defaultdict(int)
        self.clock = 0
        self.max_heap = []

    def push(self, val: int) -> None:
        self.clock += 1
        self.count_map[val] += 1
        heappush(self.max_heap, Element(val, self.count_map[val], self.clock))

    def pop(self) -> int:
        top_element = heappop(self.max_heap)
        self.count_map[top_element.val] -= 1
        return top_element.val

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()