# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        fans = set()
        for c in range(n):
            if c not in fans:
                for f in range(c + 1, n):
                    if knows(c, f):
                        fans.add(c)
                        break
                    else:
                        fans.add(f)
                else:
                    for f in range(0, n):
                        if f == c:
                            continue
                        elif knows(c, f) or not knows(f, c):
                            return -1
                    return c
        return -1


