class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [d for d in str(num)]
        for i in range(len(digits) - 1):
            max_digit_index = i
            for k in range(i + 1, len(digits)):
                if digits[max_digit_index] <= digits[k]:
                    max_digit_index = k
            if digits[max_digit_index] > digits[i]:
                digits[i], digits[max_digit_index] = digits[max_digit_index], digits[i]
                return int(''.join(digits))
        return num
