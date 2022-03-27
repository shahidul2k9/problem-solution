from typing import List


class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        n = len(cars)
        ht = [-1] * n
        stack = []

        def collistionTime(a, b):
            if a[2] <= b[2]:
                return float('inf')
            else:
                return (b[1] - a[1]) / (a[2] - b[2])

        def pushForward():
            if len(stack) >= 2:
                f1, p1, s1 = stack.pop()
                f2, p2, s2 = stack[-1]
                d = p2 - p1
                s = s1 - s2
                ht[f1] = d / s
                return True
            return False

        for i in range(len(cars) - 1, -1, -1):
            (p, s) = cars[i]
            if stack:
                while len(stack) > 1 and collistionTime((i, p, s), stack[-1]) > collistionTime(stack[-1], stack[-2]):
                    pushForward()
                if s <= stack[-1][2]:
                    stack.clear()
                stack.append((i, p, s))
            else:
                stack.append((i, p, s))
        while len(stack) > 1:
            pushForward()
        return ht


print(Solution().getCollisionTimes([[1,2],[2,1],[4,3],[7,2]]))
print(Solution().getCollisionTimes([[3, 4], [5, 4], [6, 3], [9, 1]]))
# s/v = t