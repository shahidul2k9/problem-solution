class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        n = len(s)
        matching_pos = [-1] * n
        i = 0
        stack = []
        for i in range(n):
            if s[i] == '(':
                stack.append(i)
            else:
                left = stack.pop()
                matching_pos[left] = i
                matching_pos[i] = left

        def count_score(i, j):
            if i >= j:
                return 0
            right = matching_pos[i]
            if i + 1 == right:
                return 1 + count_score(right + 1, j)
            return 2 * count_score(i + 1, right - 1) + count_score(right + 1, j)

        return count_score(0, n - 1)
