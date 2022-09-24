class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        index = 0
        n = len(s)
        limit = 1 << 31
        ans = 0
        sign = 1
        if index < n and s[index] in ['+', '-']:
            if s[index] == '-':
                sign = -1
            else:
                sign = 1
            index += 1

        while index < n and s[index].isdigit():
            ans = ans * 10 + ord(s[index]) - ord('0')
            if ans >= limit:
                break
            index += 1
        if sign == 1:
            ans = min(ans, (1 << 31) - 1)
        else:
            ans = min(ans, 1 << 31)
        return ans * sign