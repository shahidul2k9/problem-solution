from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        lds = [1] * n
        pi = [k for k in range(n)]
        for e in range(n):
            for s in range(e):
                if nums[e] % nums[s] == 0 and lds[e] < lds[s] + 1:
                    lds[e] = lds[s] + 1
                    pi[e] = s
        k = max([(lds[k], k) for k in range(n)])[1]
        seq = []
        while k != pi[k]:
            seq.append(nums[k])
            k = pi[k]
        seq.append(nums[k])
        return seq[::-1]

