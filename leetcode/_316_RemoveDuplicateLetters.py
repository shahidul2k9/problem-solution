class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = []
        lc = {k: v for k, v in enumerate(s)}
        picked = set()
        for i, c in enumerate(s):
            if c not in picked:
                while stack and stack[-1] > c and lc[stack[-1]] > i:
                    picked.remove(stack.pop())
                stack.append(c)
                picked.add(c)
        return ''.join(stack)
