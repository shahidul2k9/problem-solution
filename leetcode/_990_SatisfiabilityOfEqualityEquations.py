from typing import List


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        s = [i for i in range(26)]

        def find_parent(i):
            if s[i] == i:
                return i
            else:
                s[i] = find_parent(s[i])
                return s[i]

        for e in equations:
            if '!' not in e:
                x, y = e[:1], e[-1:]
                a, b = ord(x) - ord('a'), ord(y) - ord('a')
                s[find_parent(a)] = find_parent(b)
        for e in equations:
            if '!' in e:
                x, y = e[:1], e[-1:]
                a, b = ord(x) - ord('a'), ord(y) - ord('a')
                if find_parent(a) == find_parent(b):
                    return False
        return True
