class Solution(object):
    def findTheWinner(self, n, k):
        circle = [i for i in range(1, n + 1)]
        p = 0
        while len(circle) > 1:
            p = (p + k - 1) % len(circle)
            circle.pop(p)
            if p == len(circle):
                p = 0
        return circle[0]
