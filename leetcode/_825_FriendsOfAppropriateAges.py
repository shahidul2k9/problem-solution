import collections
from typing import List


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        age_group = collections.Counter(ages)
        friend_request = 0
        for x, xn in age_group.items():
            for y, yn in age_group.items():
                if not (y <= 0.5 * x + 7 or y > x):
                    friend_request += xn * yn
                    if x == y:
                        friend_request -= xn
        return friend_request
