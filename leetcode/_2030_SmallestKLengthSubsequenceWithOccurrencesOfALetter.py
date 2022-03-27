class Solution:
    def smallestSubsequence(self, s: str, k: int, letter: str, repetition: int) -> str:
        n = len(s)
        upf = 0
        for c in s:
            if c == letter:
                upf += 1
        pf = 0
        stack = []
        for i, c in enumerate(s):
            while stack and (n - i) + len(stack) > k and stack[-1] > c:
                if stack[-1] == letter and upf + pf - 1 < repetition:
                    break
                if stack.pop() == letter:
                    pf -= 1
            if len(stack) < k and (c == letter or len(stack) + repetition - pf < k):
                stack.append(c)
                if c == letter:
                    pf += 1
            if c == letter:
                upf -= 1
        return ''.join(stack)
