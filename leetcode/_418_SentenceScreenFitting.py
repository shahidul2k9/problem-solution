from typing import List


class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        text = ' '.join(sentence) + ' '
        skip = [0] * len(text)
        for i in range(1, len(skip)):
            if text[i] == ' ':
                skip[i] = -1
            else:
                skip[i] = skip[i - 1] + 1

        n = 0
        for r in range(rows):
            n += cols
            next_pos = n % len(text)
            if text[
                next_pos] == ' ':  # next char is space so it is pointless to start with next row(implict contribution)
                n += 1
            else:
                n -= skip[next_pos]  # might need to void some space for a word prefix

        return n // len(text)