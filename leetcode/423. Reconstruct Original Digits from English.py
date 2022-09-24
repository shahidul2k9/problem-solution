from collections import Counter


class Solution:
    def originalDigits(self, s: str) -> str:
        scan_sequence = [(0, 'zero', 'z'), (2, 'two', 'w'), (4, 'four', 'u'), (6, 'six', 'x'), (7, 'seven', 's'),
                         (5, 'five', 'v'), (8, 'eight', 'g'), (3, 'three', 'r'), (1, 'one', 'o'), (9, 'nine', 'i')]
        char_counter = Counter(s)
        digits = []
        for digit, word, key_char in scan_sequence:
            factor = char_counter[key_char]
            if factor > 0:
                for ch, f in Counter(word).items():
                    char_counter[ch] -= f * factor
                digits.append(str(digit) * factor)
        digits.sort()
        return ''.join(digits)
