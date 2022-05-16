import collections


class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        f = collections.defaultdict(int)
        left = right = 0
        sub_len = 0
        while right < len(s):
            ch = s[right]
            f[ch] += 1
            while len(f) > k:
                ch = s[left]
                if f[ch] == 1:
                    del f[ch]
                else:
                    f[ch] -= 1
                left += 1
            right += 1
            sub_len = max(right - left, sub_len)
        return sub_len



