class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        val = 0
        val_set = set()
        for i in range(len(s)):
            ith_bit = ord(s[i]) - ord('0')
            if i + 1 < k:
                val += (ith_bit << i)
            else:
                val += (ith_bit << k - 1)
                val_set.add(val)
                val = val >> 1
        return len(val_set) == (1 << k)



