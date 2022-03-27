from collections import Counter, defaultdict


class Solution:
    def smallestSubsequence(self, s: str) -> str:
        fc = Counter(s)
        stack = []
        stack_fc = defaultdict(int)
        for c in s:
            while stack and stack_fc[c] == 0 and stack[-1] > c and fc[stack[-1]] > 0:
                stack_fc[stack.pop()] -= 1
            if stack_fc[c] == 0:
                stack.append(c)
                stack_fc[c] += 1
            fc[c] -= 1
        return ''.join(stack)


#print(Solution().smallestSubsequence("cbaacabcaaccaacababa"))
