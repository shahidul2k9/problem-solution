from typing import List


class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        stretchy_words_count = 0

        def count_word_group(ch: str, s: str, pos: int):
            if pos < 0:
                return 0
            i = pos
            while i < len(s) and ch == s[i]:
                i += 1
            return i - pos

        for w in words:
            i = k = 0
            is_stretchy = False

            while i < len(s) and k < len(w):
                di = count_word_group(s[i], s, i)
                dk = count_word_group(w[k], w, k)

                if s[i] != w[k] or (di != dk and (dk > di or di <= 2) ):
                    is_stretchy = False
                    break
                if di >= 3:
                    is_stretchy = True
                i += di
                k += dk
            if is_stretchy and i == len(s) and k == len(w):
                stretchy_words_count += 1
        return stretchy_words_count