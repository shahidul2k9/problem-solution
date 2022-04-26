from typing import List


class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        i = j = 0
        while i < len(slots1) and j < len(slots2):
            a, b = slots1[i]
            c, d = slots2[j]
            if b - a < duration:
                i += 1
            elif d - c < duration:
                j += 1
            else:
                x,y = max(a,c), min(b,d)
                if x <= y and y - x >= duration:
                    return [x, x + duration]
                else:
                    if a < c:
                        i += 1
                    else:
                        j += 1
        return []