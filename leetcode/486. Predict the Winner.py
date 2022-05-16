from typing import List
from functools import lru_cache


class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        @lru_cache
        def opt_score(a, b) -> List[int]:
            if a == b:
                return [nums[a], 0]
            else:
                score1 = opt_score(a + 1, b)[:][::-1]
                score1[0] += nums[a]
                score2 = opt_score(a, b - 1)[:][::-1]
                score2[0] += nums[b]
                if score1[0] > score2[0]:
                    return score1
                else:
                    return score2

        score = opt_score(0, len(nums) - 1)
        return score[0] >= score[1]

