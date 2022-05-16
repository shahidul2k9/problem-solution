class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        lps = [0] * n
        left = 0
        i = 1
        while i < len(s):
            if s[i] == s[left]:
                left += 1
                lps[i] = left
                i += 1
            else:
                if left > 0:
                    left = lps[left - 1]
                else:
                    lps[i] = 0
                    i += 1

        text = s[::-1]
        i = k = 0
        while i < len(text):
            if text[i] == s[k]:
                i += 1
                k += 1
            else:
                if k == 0:
                    i += 1
                else:
                    k = lps[k - 1]
        return s[k:][::-1] + s