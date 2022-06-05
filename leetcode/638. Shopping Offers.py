from typing import List


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        n = len(needs)
        dp = dict()
        dp[tuple([0] * n)] = 0

        def lowest_price(targets) -> int:
            key = tuple(targets)
            if key not in dp:
                new_target = [0] * n
                opt_val = 0
                dot = 0
                for i in range(n):
                    dot += price[i] * targets[i]
                opt_val = dot

                for spoff in special:
                    for i in range(n):
                        if targets[i] >= spoff[i]:
                            new_target[i] = targets[i] - spoff[i]
                        else:
                            break
                    else:
                        opt_val = min(opt_val, lowest_price(new_target) + spoff[n])
                dp[key] = opt_val
            return dp[key]

        ans = lowest_price(needs)
        return ans
