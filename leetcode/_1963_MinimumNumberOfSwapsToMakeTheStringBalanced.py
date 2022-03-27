class Solution:
    def minSwaps(self, s: str) -> int:
        stack = []
        for b in s:
            if b == ']' and stack and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(b)
        return len(stack) // 4 + (1 if len(stack) % 4 == 2 else 0)
