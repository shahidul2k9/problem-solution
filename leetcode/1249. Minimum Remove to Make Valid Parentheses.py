class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        n = len(s)
        deleted = [False] * n
        balance = 0
        for i, ch in enumerate(s):
            if ch == '(':
                balance += 1
            elif ch == ')':
                balance -= 1
            if balance < 0:
                deleted[i] = True
                balance = 0
        i = n - 1
        while balance > 0:
            if s[i] == '(':
                balance -= 1
                deleted[i] = True
            i -= 1
        seq = []
        for i, ch in enumerate(s):
            if not deleted[i]:
                seq.append(ch)
        return ''.join(seq)
