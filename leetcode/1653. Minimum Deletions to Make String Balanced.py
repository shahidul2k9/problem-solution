import collections


class Solution:
    def minimumDeletions(self, s: str) -> int:
        f = collections.Counter(s)
        left_b = 0
        right_a = f['a']
        ans = len(s)
        for i in range(0, len(s) + 1):
            ans = min(left_b + right_a, ans)
            if i < len(s):
                if s[i] == 'b':
                    left_b += 1
                else:
                    right_a -= 1

        return ans