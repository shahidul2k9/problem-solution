class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        f = [0] * 26
        for c in s:
            c_val = ord(c) - ord('a')
            f[c_val] += 1
        msc = 0
        for c in s:
            c_val = ord(c) - ord('a')
            n = f[c_val]
            msc = msc + n
            f[c_val] -= 1
        return msc