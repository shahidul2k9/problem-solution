class Solution:
    def twoEggDrop(self, n: int) -> int:
        ans = cur_n = 1
        while cur_n < n:
            ans += 1
            cur_n += ans
        return ans

        """"
        output patter
        -------------
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5
        ...
        @lru_cache(None)
        def min_drop(rem_n : int, rem_egg : int)-> int:
            if rem_egg == 1:
                return rem_n
            elif rem_n == 0:
                return 0
            else:
                min_moves = float('inf')
                for i in range(1, rem_n + 1):
                    min_moves = min(min_moves, 1 + max(min_drop(rem_n - i, rem_egg), min_drop(i - 1, rem_egg - 1)))
                return min_moves
        return min_drop(n, 2)
        """
