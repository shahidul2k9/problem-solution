class Solution:
    def trailingZeroes(self, n: int) -> int:
        twos = fives = 0
        for x in range(2, n + 1):
            while x % 2 == 0:
                x = x // 2
                twos += 1
            while x % 5 == 0:
                x = x // 5
                fives += 1
        return min(twos, fives)

