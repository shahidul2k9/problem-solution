from typing import List


class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def match(i: int, s: str, j: int, t: str):
            if i >= len(s):
                return j >= len(t) or t[j:].islower()
            elif j >= len(t):
                return False
            else:
                if s[i] == t[j]:
                    return match(i + 1, s, j + 1, t)
                elif t[j].isupper():
                    return False
                else:
                    return match(i, s, j + 1, t)

        return [match(0, pattern, 0, t) for t in queries]
