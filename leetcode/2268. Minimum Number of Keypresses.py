from collections import Counter


class Solution:
    def minimumKeypresses(self, s: str) -> int:
        frequency = Counter(s)
        press_count = 0
        index = 0
        for ch, f in sorted(frequency.items(), key=lambda x: x[1], reverse=True):
            press = 1 if index < 9 else (2 if index < 18 else 3)
            press_count += f * press
            index += 1
        return press_count


