class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n % 2 != 0:
            return False
        else:
            close_prefix = 0
            open_suffix = 0
            for i in range(n):
                if s[i] == ')' and locked[i] == '1':
                    close_prefix += 1
                if s[~i] == '(' and locked[~i] == '1':
                    open_suffix += 1
                if 2 * close_prefix > i + 1 or 2 * open_suffix > i + 1:
                    return False
        return True


print(Solution().canBeValid("()()", "1111"))
