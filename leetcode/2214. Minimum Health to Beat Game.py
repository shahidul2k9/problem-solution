from typing import List


class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        total_damage = sum(damage)
        max_armor_use = min(armor, max(damage))

        return total_damage - max_armor_use + 1


