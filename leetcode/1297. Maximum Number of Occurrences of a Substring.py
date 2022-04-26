import collections


class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        sbc = collections.defaultdict(int)
        for sz in range(minSize, maxSize + 1):
            wf = [0] * 26
            for i, ch in enumerate(s):
                idx = ord(ch) - ord('a')
                wf[idx] += 1
                if i + 1 >= sz:
                    unique_chars = 0
                    for k in range(26):
                        if wf[k] >= 1:
                            unique_chars += 1
                            if unique_chars > maxLetters:
                                break
                    else:
                        sbc[s[i - sz + 1: i + 1]] += 1
                    left_idx = ord(s[i - sz + 1]) - ord('a')
                    wf[left_idx] -= 1
            return max(sbc.values()) if len(sbc) > 0 else 0




