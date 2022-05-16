import collections


class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        fc = collections.defaultdict(int)
        left = right = 0
        mx_sub_len = 0
        while right < len(s):
            fc[s[right]] += 1
            while len(fc) > 2:
                ch = s[left]
                fc[ch] -= 1
                if fc[ch] == 0:
                    del fc[ch]
                left += 1
            right += 1
            mx_sub_len = max(mx_sub_len, right - left)
        return mx_sub_len

