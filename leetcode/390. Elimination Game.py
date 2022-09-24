class Solution:
    def lastRemaining(self, n: int) -> int:
        def f(x: int, from_left: bool) -> int:
            if x == 1:
                return 1
            elif x % 2 == 0 and not from_left:
                return 2 * f(x // 2, not from_left) - 1
            else:
                return 2 * f(x // 2, not from_left)

        return f(n, True)
