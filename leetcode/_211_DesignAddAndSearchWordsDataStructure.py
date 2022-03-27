class WordDictionary:

    def __init__(self):
        self.t = {}

    def addWord(self, word: str) -> None:
        t = self.t
        for c in word:
            if c not in t:
                t[c] = {}
            t = t[c]
        t['$'] = True

    def search(self, word: str) -> bool:

        def dfs(s, w, t: dict):
            if len(w) == s:
                return '$' in t
            if w[s] == '.':
                for tk, tv in t.items():
                    if tk != '$' and dfs(s + 1, w, tv):
                        return True
            elif w[s] in t:
                return dfs(s + 1, w, t[w[s]])
            else:
                return False

        return dfs(0, word, self.t)
