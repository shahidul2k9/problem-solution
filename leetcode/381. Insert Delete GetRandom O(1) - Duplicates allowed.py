import collections
import random


class RandomizedCollection:

    def __init__(self):
        self.nums = []
        self.id_set = collections.defaultdict(set)

    def insert(self, val: int) -> bool:
        self.nums.append(val)
        self.id_set[val].add(len(self.nums) - 1)
        return len(self.id_set[val]) == 1

    def remove(self, val: int) -> bool:
        if len(self.id_set[val]) > 0:
            remove_index = self.id_set[val].pop()
            last_index = len(self.nums) - 1
            last_index_value = self.nums.pop()
            if remove_index != last_index:
                self.nums[remove_index] = last_index_value
                self.id_set[last_index_value].discard(last_index)
                self.id_set[last_index_value].add(remove_index)
            return True
        else:
            return False

    def getRandom(self) -> int:
        return random.choice(self.nums)

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()