# The read4 API is already defined for you.
# def read4(buf4: List[str]) -> int:
from typing import List


class Solution:
    def __init__(self):
        self.buf4 = [''] * 4
        self.buf4_count = 0

    def load_into_buffer(self) -> bool:
        if self.buf4_count == 0:
            self.buf4_count = read4(self.buf4)
        return self.buf4_count > 0

    def read(self, buf: List[str], n: int) -> int:
        index = 0
        while index < n and self.load_into_buffer():
            transfer_count = min(self.buf4_count, n - index)
            k = 0
            while k < transfer_count:
                buf[index] = self.buf4[k]
                k += 1
                index += 1
            while k < self.buf4_count:
                self.buf4[k - transfer_count] = self.buf4[k]
                k += 1
            self.buf4_count -= transfer_count
        return index