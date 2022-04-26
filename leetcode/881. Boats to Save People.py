from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        l = 0
        r = len(people) - 1
        boats = 0
        while l <= r:
            if l == r:
                l += 1
                r -= 1
            else:
                if people[l] + people[r] <= limit:
                    l += 1
                    r -= 1
                else:
                    r -= 1
            boats += 1
        return boats