import collections
from typing import List


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        stone_set = {stone_position for stone_position in stones}
        start = stones[0]
        end = stones[-1]
        dp = {(start, 0)}
        q = collections.deque([(start, 0)])
        while q:
            u, k = q.popleft()
            if u == end:
                return True
            for dk in [-1, 0, 1]:
                v = u + k + dk
                next = (v, k + dk)
                if v > u and v in stone_set and next not in dp:
                    q.append(next)
                    dp.add(next)
        return False

