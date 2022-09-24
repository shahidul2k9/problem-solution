from typing import List


class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        opt_val = baseCosts[0]

        def bracktrack(topping_index: int, val: int):
            nonlocal opt_val
            if abs(target - val) < abs(target - opt_val):
                opt_val = val
            elif abs(target - val) == abs(target - opt_val) and val < opt_val:
                opt_val = val
            if topping_index < len(toppingCosts):
                topping_val = toppingCosts[topping_index]
                for topping_count in range(0, 3):
                    bracktrack(topping_index + 1, topping_count * topping_val + val)

        for ice_cost in baseCosts:
            bracktrack(0, ice_cost)
        return opt_val
