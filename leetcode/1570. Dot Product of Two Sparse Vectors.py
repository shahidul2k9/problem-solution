from typing import List


class SparseVector:
    def __init__(self, nums: List[int]):
        self.em = {}
        for i, v in enumerate(nums):
            if v != 0:
                self.em[i] = v

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        ans = 0
        for k, v in vec.em.items():
            if k in self.em:
                ans += v * self.em[k]
        return ans

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)