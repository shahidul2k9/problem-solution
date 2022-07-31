import collections
from typing import List


class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.nums2_frequency = collections.Counter(nums2)

    def add(self, index: int, val: int) -> None:

        self.nums2_frequency[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.nums2_frequency[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        pairs = 0
        for val1 in self.nums1:
            val2 = tot - val1
            if val2 in self.nums2_frequency:
                pairs += self.nums2_frequency[val2]
        return pairs

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)