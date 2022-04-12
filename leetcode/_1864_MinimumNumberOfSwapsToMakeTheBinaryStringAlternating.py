class Solution:
    def minSwaps(self, s: str) -> int:
        on = off = 0
        for c in s:
            if c == '0':
                off += 1
            else:
                on += 1
        av = abs(on - off)
        if av > 1:
            return -1
        else:
            msc = 0
            target_char = None
            if on > off:
                target_char = '1'
            else:
                target_char = '0'
            for i in range(0, len(s), 2):
                if s[i] != target_char:
                    msc += 1
            if av == 0:
                return min(msc, on - msc)
            else:
                return msc





