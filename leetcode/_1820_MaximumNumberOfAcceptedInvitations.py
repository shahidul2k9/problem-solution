from collections import defaultdict, deque
from typing import List


class Solution:
    def maximumInvitations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        tnv = m + n + 2
        s = m + n
        t = m + n + 1
        g = defaultdict(set)
        adj = [[0] * tnv for _ in range(tnv)]
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    u, v = i, j + m
                    g[u].add(v)
                    g[v].add(u)
                    adj[u][v] = 1

        for v in range(m):
            g[s].add(v)
            g[v].add(s)
            adj[s][v] = 1
        for u in range(m, m + n):
            g[t].add(u)
            g[u].add(t)
            adj[u][t] = 1

        def dfs(s, t, par):
            par[s] = s
            color = {s}
            q = deque([s])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if adj[u][v] > 0 and v not in color:
                        q.append(v)
                        color.add(v)
                        par[v] = u
                        if v == t:
                            return True

            return False

        matched = 0
        par = [None] * tnv

        while dfs(s, t, par):
            matched += 1
            v = t
            while v != s:
                u = par[v]
                adj[u][v] -= 1
                adj[v][u] += 1
                v = u
            par = [None] * tnv
        return matched
