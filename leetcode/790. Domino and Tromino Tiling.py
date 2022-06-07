from functools import lru_cache


class Solution:

    def numTilings(self, n: int) -> int:
        mod = (10 ** 9 + 7)

        @lru_cache
        def partial(k) -> int:
            if k == 2:
                return 1
            else:
                return (full(k - 2) + partial(k - 1)) % mod

        @lru_cache(maxsize=None)
        def full(k) -> int:
            if k < 3:
                return k
            else:
                return (full(k - 1) + full(k - 2) + 2 * partial(k - 1)) % mod

        return full(n)
