class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for c in s:
            if stack and stack[-1][0] == c:
                if stack[-1][1] + 1 == k:
                    stack.pop()
                else:
                    _, pc = stack.pop()
                    stack.append((c, pc + 1))
            else:
                stack.append((c, 1))
        return ''.join([c * n for c, n in stack])
