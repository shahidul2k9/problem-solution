class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = 0
        if dividend < 0:
            sign += 1
            dividend = -dividend
        if divisor < 0:
            sign += 1
            divisor = -divisor
        if sign == 2:
            sign = 0

        quotient = 0
        subtracted = 0
        while dividend - (subtracted + divisor) >= 0:
            q = 1
            s = divisor
            while dividend - (subtracted + s) >= 0:
                quotient += q
                subtracted += s
                q += q
                s += s
        if sign == 0:
            quotient = min(quotient, (1 << 31) - 1)
        else:
            quotient = -min(quotient, 1 << 31)
        return quotient




