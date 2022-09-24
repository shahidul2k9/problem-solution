class Solution:
    def checkValidString(self, s: str) -> bool:
        min_balance = max_balance = 0  # keep track of range of stage(s)
        for ch in s:
            left = right = 0
            if ch == '(':
                left = right = 1
            elif ch == ')':
                left = right = -1
            else:
                left = -1
                right = 1

            min_balance += left
            max_balance += right
            if max_balance < 0:
                break
            min_balance = max(min_balance, 0)  # skip invaid state(s)
        return min_balance <= 0 <= max_balance
