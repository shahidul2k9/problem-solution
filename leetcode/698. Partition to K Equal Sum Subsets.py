from typing import List


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        n = len(nums)
        nums.sort(reverse=True)
        taken = 0
        dp = {}

        def bracktrack(ck: int, index: int, ct: int) -> int:
            nonlocal taken
            if ck == 0:
                return True
            if taken in dp:
                return dp[taken]
            if ct == 0:
                dp[taken] = bracktrack(ck - 1, 0, total // k)
                return dp[taken]
            for i in range(index, n):
                if not (1 << i & taken) and ct - nums[i] >= 0:
                    taken = taken | (1 << i)
                    if bracktrack(ck, i + 1, ct - nums[i]):
                        return True
                    taken = taken ^ (1 << i)
            dp[taken] = False
            return dp[taken]

        if total % k == 0 and max(nums) <= total // k:
            return bracktrack(k, 0, total // k)
        else:
            return False
