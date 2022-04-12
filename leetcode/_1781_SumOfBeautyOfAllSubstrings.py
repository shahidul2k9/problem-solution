from collections import defaultdict
class Solution:
    def beautySum(self, s: str) -> int:
        beauty = 0
        for left in range(len(s)):
            fc = defaultdict(int)
            max_f = 0
            for right in range(left, len(s)):
                ch = s[right]
                fc[ch] += 1
                max_f = max(max_f, fc[ch])
                beauty += (max_f - min(fc.values()))
        return beauty