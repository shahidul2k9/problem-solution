from typing import List


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def insert(word: str):
            t = root
            for ch in word:
                if ch not in t:
                    t[ch] = {}
                t = t[ch]
            t['$'] = True

        def dfs(r, c, w, t):
            ch = board[r][c]
            if ch in t:
                if '$' in t[ch]:
                    word_set.add(w + ch)
                    del t[ch]['$']
                for dr, dc in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and board[nr][nc] != ' ':
                        board[r][c] = ' '
                        dfs(nr, nc, w + ch, t[ch])
                        board[r][c] = ch
                if len(t[ch]) == 0:
                    del t[ch]

        m, n = len(board), len(board[0])
        root = {}
        for w in words:
            insert(w)
        word_set = set()
        for r in range(m):
            for c in range(n):
                dfs(r, c, '', root)
        return list(word_set)


print(Solution().findWords([["o", "a", "a", "n"], ["e", "t", "a", "e"], ["i", "h", "k", "r"], ["i", "f", "l", "v"]],
                           ["oath", "pea", "eat", "rain"]))
