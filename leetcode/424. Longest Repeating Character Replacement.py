import collections


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        fc = collections.defaultdict(int)
        left = right = ans = 0
        while right < len(s):
            rch = s[right]
            fc[rch] += 1
            while (right - left + 1 - max(fc.values())) > k:
                lch = s[left]
                fc[lch] -= 1
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        return ans