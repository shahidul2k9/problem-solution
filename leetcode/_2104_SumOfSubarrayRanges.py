class Solution:
    def subArrayRanges(self, nums: list[int]) -> int:
        n = len(nums)
        low = [x for x in nums]
        high = [x for x in nums]
        sum = 0
        for d in range(1, n, 1):
            for i in range(0, n - d):
                low[i] = min(low[i], nums[i + d])
                high[i] = max(high[i], nums[i + d])
                sum = sum + high[i] - low[i]

        return sum
#print(Solution().subArrayRanges([1, 2, 3]))
