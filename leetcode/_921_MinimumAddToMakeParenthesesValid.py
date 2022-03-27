class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        ins = 0
        for p in s:
            if p == '(':
                stack.append(p)
            elif len(stack) == 0 or stack.pop() != '(':
                ins += 1
        return ins + len(stack)
