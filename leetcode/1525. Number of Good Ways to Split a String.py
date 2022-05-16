class Solution:
    def numSplits(self, s: str) -> int:
        left = [0] * 26
        right = [0] * 26
        for c in s:
            right[ord(c) - ord('a')] += 1
        good_splits = 0
        for i in range(len(s)):
            bal = 0
            for ci in range(26):
                if left[ci] > 0:
                    bal += 1
                if right[ci] > 0:
                    bal -= 1
            if bal == 0:
                good_splits += 1

            ci = ord(s[i]) - ord('a')
            left[ci] += 1
            right[ci] -= 1
        return good_splits


