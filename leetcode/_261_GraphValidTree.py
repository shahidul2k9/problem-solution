from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        par = [None] * n
        for u in range(n):
            par[u] = u

        def find_parent(u):
            if par[u] == u:
                return u
            else:
                par[u] = find_parent(par[u])
                return par[u]

        for u, v in edges:
            a = find_parent(u)
            b = find_parent(v)
            if a == b:
                return False
            else:
                par[a] = b
        for u in range(1, n):
            if find_parent(u) != find_parent(0):
                return False
        return True

