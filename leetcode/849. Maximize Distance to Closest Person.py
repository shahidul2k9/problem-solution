from typing import List


class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        left = float('-inf')
        right = 0
        while right < len(seats) and seats[right] == 0:
            right += 1

        opt_dist = 0
        for i, sv in enumerate(seats):
            if sv == 1:
                left = i
            else:
                d = min(i - left, right - i)
                opt_dist = max(opt_dist, d)
            if right <= i:
                right += 1
                while right < len(seats) and seats[right] == 0:
                    right += 1
                if right == len(seats):
                    right = float('inf')
        return opt_dist
