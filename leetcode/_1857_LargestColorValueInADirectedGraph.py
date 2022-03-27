import collections


class Solution:
    def largestPathValue(self, colors: str, edges: list[list[int]]) -> int:
        n = len(colors)
        g = collections.defaultdict(list)
        d = [0 for _ in range(n)]
        for e in edges:
            u = e[0]
            v = e[1]
            g[u].append(v)
            d[v] += 1
        q = []
        dp = collections.defaultdict(lambda: [0 for _ in range(26)])

        for u in range(n):
            if d[u] == 0:
                q.append(u)

        cut_off_nones = 0
        while q:
            u = q.pop()
            cut_off_nones += 1
            ch = ord(colors[u]) - ord('a')
            dp[u][ch] += 1
            for v in g[u]:
                d[v] -= 1
                if d[v] == 0:
                    q.append(v)
                for c in range(26):
                    dp[v][c] = max(dp[v][c], dp[u][c])

        if cut_off_nones != n:
            return -1
        else:
            max_color = 0
            for u in range(n):
                for c in range(26):
                    max_color = max(max_color, dp[u][c])
            return max_color