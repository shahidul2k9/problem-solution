class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorial = [1]
        sequence = [str(i) for i in range(1, n+1)]
        for i in range(1, n):
            factorial.append(i * factorial[i-1])
        permuation = []
        k -= 1
        for i in range(n-1, -1, -1):
            digit_index = k // factorial[i]
            k -= digit_index * factorial[i]
            permuation.append(sequence[digit_index])
            del sequence[digit_index]
        return ''.join(permuation)
