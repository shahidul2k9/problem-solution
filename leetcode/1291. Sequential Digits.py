from typing import List


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        num_seq = []

        def generate(max_digits, digits, val, last_digit):
            if digits <= max_digits:
                if val <= high:
                    if val >= low:
                        num_seq.append(val)
                    next_digit = last_digit + 1
                    if next_digit <= 9:
                        next_val = val * 10 + next_digit
                        generate(max_digits, digits + 1, next_val, next_digit)

        for d in range(1, 10):
            generate(len(str(high)), 1, d, d)

        num_seq.sort()
        return num_seq