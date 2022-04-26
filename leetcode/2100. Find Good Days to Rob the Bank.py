from typing import List


class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)

        post_sc = [1] * n
        before_sc = [1] * n
        for i in range(n - 1):
            if security[n - i - 2] <= security[n - i - 1]:
                post_sc[n - i - 2] = 1 + post_sc[n - i - 1]

            if security[i] >= security[i + 1]:
                before_sc[i + 1] = before_sc[i] + 1
        print(before_sc)
        print(post_sc)

        robbing_days = []
        for i in range(time, n - time):
            if before_sc[i] > time and post_sc[i] > time:
                robbing_days.append(i)
        return robbing_days
