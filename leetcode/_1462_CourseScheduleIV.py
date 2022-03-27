from typing import List


class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[
        bool]:
        n = numCourses
        rg = [set() for _ in range(n)]
        ps = {}
        for u, v in prerequisites:
            rg[v].add(u)

        def dfs(u):
            if u in ps:
                return ps[u]
            p = {u}
            for v in rg[u]:
                p |= dfs(v)
            ps[u] = p
            return p

        for u in range(n):
            dfs(u)
        ans = []
        for u, v in queries:
            ans.append(u in ps[v])
        return ans
