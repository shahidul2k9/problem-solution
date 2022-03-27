class Solution:
    def countVowels(self, word: str) -> int:
        nv = 0
        ans = 0
        for i, ch in enumerate(word):
            if ch in {'a', 'e', 'i', 'o', 'u'}:
                ans = ans + (i + 1) * (len(word) - i)
        return ans
