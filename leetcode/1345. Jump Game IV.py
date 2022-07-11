import collections
from typing import List


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        positions = collections.defaultdict(set)
        n = len(arr)
        for i, v in enumerate(arr):
            positions[v].add(i)
        q = collections.deque([0])
        dp = [-1] * n
        dp[0] = 0
        while q:
            from_index = q.popleft()
            from_distance = dp[from_index]
            if from_index == n - 1:
                return dp[from_index]

            for next_index in positions[arr[from_index]]:
                if dp[next_index] == -1:
                    dp[next_index] = from_distance + 1
                    q.append(next_index)
            positions[arr[from_index]].clear()
            if from_index > 0 and dp[from_index - 1] == -1:
                dp[from_index - 1] = from_distance + 1
                q.append(from_index - 1)
            if from_index + 1 < n and dp[from_index + 1] == -1:
                dp[from_index + 1] = from_distance + 1
                q.append(from_index + 1)
