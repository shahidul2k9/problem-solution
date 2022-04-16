from collections import OrderedDict
from typing import List


class FirstUnique:

    def __init__(self, nums: List[int]):
        um = OrderedDict()
        ds = set()
        for v in nums:
            self.add_internal(v, um, ds)

        self.um = um
        self.ds = ds

    def showFirstUnique(self) -> int:
        vals = self.um.keys()
        if len(vals):
            return next(iter(vals))
        else:
            return -1

    def add(self, value: int) -> None:
        self.add_internal(value, self.um, self.ds)

    def add_internal(self, v, um, ds):
        if v not in ds:
            if v in um:
                del um[v]
                ds.add(v)
            else:
                um[v] = 1
                um.move_to_end(v)

# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)