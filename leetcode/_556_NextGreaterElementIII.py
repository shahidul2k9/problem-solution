class Solution:
    def nextGreaterElement(self, n: int) -> int:
        digits = list(str(n))
        for i in range(len(digits) - 2, -1, -1):
            if digits[i] < digits[i + 1]:
                k = len(digits) - 1
                while digits[k] <= digits[i]:
                    k -= 1
                digits[i], digits[k] = digits[k], digits[i]
                x = i + 1
                y = len(digits) - 1
                while x < y:
                    digits[x], digits[y] = digits[y], digits[x]
                    x += 1
                    y -= 1
                next_n = int(''.join(digits))
                if next_n <= (1 << 31) - 1:
                    return next_n
                else:
                    return -1
        return -1
