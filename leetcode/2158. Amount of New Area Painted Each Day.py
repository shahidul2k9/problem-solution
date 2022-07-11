from typing import List


class Solution:
    def amountPainted(self, paint: List[List[int]]) -> List[int]:
        max_end = 0
        for _, end in paint:
            max_end = max(max_end, end)
        canvas = [i for i in range(max_end + 2)]
        paint_count = [0] * len(paint)
        for i, (start, end) in enumerate(paint):
            head = start
            while head < end:
                if canvas[head] == head:
                    canvas[head], head = end, canvas[head + 1]
                    paint_count[i] += 1
                else:
                    canvas[head], head = end, canvas[head]
        return paint_count

