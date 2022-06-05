class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glasses_up = [poured]
        for row in range(0, query_row):
            glasses_down = [0]
            for i, cp in enumerate(glasses_up):
                half = max(cp - 1, 0) / 2
                glasses_down[-1] += half
                glasses_down.append(half)
            glasses_up = glasses_down
        return min(glasses_up[query_glass], 1)


