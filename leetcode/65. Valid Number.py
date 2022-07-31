class Solution:
    def isNumber(self, s: str) -> bool:
        decimal_pos = exponent_pos = None
        digit_count = 0
        digit_after_exp = 0
        for i, ch in enumerate(s):
            if ch in ['-', '+']:
                if i > 0 and (exponent_pos == None or i != exponent_pos + 1):
                    return False
            elif ch in ['e', 'E']:
                if exponent_pos != None or digit_count == 0:
                    return False
                else:
                    exponent_pos = i
            elif ch == '.':
                if decimal_pos != None or exponent_pos != None:
                    return False
                else:
                    decimal_pos = i
            elif ch.isdigit():
                digit_count += 1
                if exponent_pos != None:
                    digit_after_exp += 1
            else:
                return False

        if digit_count == 0 or (exponent_pos != None and digit_after_exp == 0):
            return False
        return True