from typing import List
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        numbers = []

        def bracktrack(num: int, rem_n: int):
            if rem_n == 0:
                numbers.append(num)
            else:
                last_digit = num % 10
                if last_digit + k < 10:
                    bracktrack(num * 10 + last_digit + k, rem_n - 1)
                if last_digit >= k and k != 0:
                    bracktrack(num * 10 + last_digit - k, rem_n - 1)

        for start_digit in range(1, 10):
            bracktrack(start_digit, n - 1)
        return numbers
