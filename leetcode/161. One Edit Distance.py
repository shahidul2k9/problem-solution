class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        def ed(p1, p2, editable):
            if p1 < 0 and p2 < 0:
                return editable == False
            elif p1 < 0:
                return p2 + 1 == 1 and editable
            elif p2 < 0:
                return p1 + 1 == 1 and editable
            else:
                if s[p1] == t[p2]:
                    return ed(p1 - 1, p2 - 1, editable)
                elif editable:
                    return ed(p1, p2 - 1, False) or ed(p1 - 1, p2, False) or ed(p1 - 1, p2 - 1, False)
                else:
                    return False

        return ed(len(s) - 1, len(t) - 1, True)
