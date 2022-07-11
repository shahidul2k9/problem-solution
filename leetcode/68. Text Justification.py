from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        sentences = []
        n = len(words)
        start = end = 0
        width = 0
        while end < n:
            if width + (end - start) + len(words[end]) <= maxWidth:
                width += len(words[end])
                end += 1
            else:
                sentence = []
                if start + 1 == end:
                    sentence.append(words[start])
                    sentence.extend([' '] * (maxWidth - len(sentence[-1])))
                    start = end
                else:
                    total_spaces = maxWidth - width
                    avg_spaces = total_spaces // (end - start - 1)
                    extra_spaces = total_spaces % (end - start - 1)
                    while start < end - 1:
                        sentence.append(words[start])
                        sentence.extend([' '] * avg_spaces)
                        if extra_spaces > 0:
                            sentence.append(' ')
                            extra_spaces -= 1
                        start += 1

                    sentence.append(words[end - 1])
                    start = end
                sentences.append(''.join(sentence))
                width = 0
        if start < end:
            last_sentence = ' '.join(words[start:end])
            right_padding = ''.join([' '] * (maxWidth - len(last_sentence)))
            sentences.append(last_sentence + right_padding)
        return sentences



