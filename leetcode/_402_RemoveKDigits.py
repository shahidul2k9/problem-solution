class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        dc = 0
        for d in num:
            while stack and stack[-1] > d and dc < k:
                stack.pop()
                dc = dc + 1
            if stack or d > '0':
                stack.append(d)
        while stack and k > 0:
            stack.pop()
        if len(stack) <= k:
            return '0'
        else:
            return ''.join(stack)
