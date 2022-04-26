from typing import List


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        def team_count(rt):
            n = len(rt)
            bigger_ns = [0] * n
            for i in range(n):
                for k in range(i + 1, n):
                    if rt[i] < rt[k]:
                        bigger_ns[i] += 1
            teams = 0
            for i in range(n):
                for j in range(i + 1, n):
                    if rt[i] < rt[j]:
                        teams += bigger_ns[j]
            return teams

        return team_count(rating) + team_count(rating[::-1])
