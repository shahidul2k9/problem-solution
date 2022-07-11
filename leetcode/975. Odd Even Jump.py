from typing import List


class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        n = len(arr)
        seq = [[val, index] for index, val in enumerate(arr)]
        seq.sort()
        greater = [-1] * n
        lower = [-1] * n
        stack = []
        for val, index in seq:
            while stack and stack[-1] < index:
                greater[stack.pop()] = index
            stack.append(index)
        seq.sort(key = lambda x : (-x[0], x[1]))
        stack.clear()
        for val, index in seq:
            while stack and stack[-1] < index:
                lower[stack.pop()] = index
            stack.append(index)
        dp = [[-1] * 2 for _ in range(n)]
        dp[n-1][0] = dp[n-1][1] = 1
        def is_good(index, jump_type)-> int:
            if dp[index][jump_type] == -1:
                ret_val = 0
                if jump_type == 1:
                    if greater[index] != -1:
                        ret_val = is_good(greater[index], 1 - jump_type)
                else:
                    if lower[index] != -1:
                        ret_val = is_good(lower[index], 1 - jump_type)
                dp[index][jump_type] = ret_val
            return dp[index][jump_type]
        good_start_count = 0
        for index in range(n):
            good_start_count += is_good(index, 1)
        return good_start_count