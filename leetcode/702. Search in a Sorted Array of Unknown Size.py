# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#    def get(self, index: int) -> int:

class Solution:
    def search(self, reader: 'ArrayReader', target: int) -> int:
        out_val = (1 << 31) - 1
        low = 0
        high = 10 ** 4
        while low <= high:
            mid = (low + high) // 2
            mid_val = reader.get(mid)
            if mid_val == out_val or mid_val > target:
                high = mid - 1
            elif target == mid_val:
                return mid
            else:
                low = mid + 1
        return -1
