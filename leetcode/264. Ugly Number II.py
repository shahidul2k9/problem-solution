class Solution:
    def __init__(self):
        self.ugly_nums = []
        heap = [1]
        seen = {1}
        while len(self.ugly_nums) < 1690:
            ugly_one = heappop(heap)
            self.ugly_nums.append(ugly_one)
            for factor in [2, 3, 5]:
                next_one = ugly_one * factor
                if next_one not in seen:
                    seen.add(next_one)
                    heappush(heap, next_one)

    def nthUglyNumber(self, n: int) -> int:
        return self.ugly_nums[n - 1]
