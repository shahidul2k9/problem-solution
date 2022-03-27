class Solution:
    def minInsertions(self, s: str) -> int:
        bl = cost = 0
        i = 0
        while i < len(s):
            if s[i] == '(':
                bl += 1
                i += 1
            else:
                if i + 1 < len(s) and s[i + 1] == ')':
                    if bl > 0:
                        bl -= 1
                    else:
                        cost += 1
                    i += 2
                else:
                    if bl > 0:
                        bl -= 1
                        cost += 1
                    else:
                        cost += 2
                    i += 1
        return cost + 2 * bl
