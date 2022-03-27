from typing import List


class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.encoding = encoding
        self.index = 0
        self.taken = 0

    def next(self, n: int) -> int:
        ex_val = -1
        while n > 0 and self.index < len(self.encoding):
            if self.encoding[self.index] - self.taken > 0:
                ex_val = self.encoding[self.index + 1]
                move_count = min(self.encoding[self.index] - self.taken, n)
                n -= move_count
                self.taken += move_count
            else:
                self.index += 2
                self.taken = 0
        return ex_val if n == 0 else -1
