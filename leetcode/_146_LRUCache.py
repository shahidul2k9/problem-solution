import collections


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.repertory = collections.OrderedDict()

    def get(self, key: int) -> int:
        repertory = self.repertory
        if key in repertory:
            repertory.move_to_end(key, last=True)
            return repertory.get(key)
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        repertory = self.repertory
        if key not in repertory:
            self.size += 1
        repertory[key] = value
        repertory.move_to_end(key, last=True)
        if self.size > self.capacity:
            repertory.popitem(last=False)
            self.size -= 1

