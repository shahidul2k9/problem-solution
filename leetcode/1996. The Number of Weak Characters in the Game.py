from typing import List


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort()
        max_defense = 0
        right = len(properties)

        weak_characters = 0
        for i in range(len(properties) - 1, -1, -1):
            at, df = properties[i]
            while right - 1 > i and properties[right - 1][0] > at:
                right -= 1
                max_defense = max(max_defense, properties[right][1])
            if max_defense > df:
                weak_characters += 1
        return weak_characters



