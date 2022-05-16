from typing import List


class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        dp_max = [[-1] * n for _ in range(n)]
        dp_diff = [[-1] * (d + 1) for _ in range(n)]
        for i in range(n):
            dp_max[i][i] = jobDifficulty[i]

        def find_max(a, b) -> int:
            if dp_max[a][b] == -1:
                dp_max[a][b] = max(jobDifficulty[a], find_max(a + 1, b))
            return dp_max[a][b]

        def min_difficulty(rp, rem_d) -> int:
            if rp < 0 and rem_d == 0:
                return 0
            if (rem_d > rp + 1) or (rem_d == 0 and rp >= 0):
                return float('inf')
            if dp_diff[rp][rem_d] == -1:
                md = float('inf')
                end = rp + 1 - rem_d + 1 + 1
                for dc in range(1, end):
                    left_pos = rp - dc + 1
                    md = min(md, find_max(left_pos, rp) + min_difficulty(left_pos - 1, rem_d - 1))
                dp_diff[rp][rem_d] = md
            return dp_diff[rp][rem_d]

        df = min_difficulty(n - 1, d)

        return -1 if df == float('inf') else df