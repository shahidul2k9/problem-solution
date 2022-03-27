class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        f = {}
        for ch in s:
            f[ch] = f.get(ch, 0) + 1
        odd_fc_count = 0
        for v in f.values():
            if v % 2 != 0:
                odd_fc_count = odd_fc_count + 1
        return odd_fc_count <= k
