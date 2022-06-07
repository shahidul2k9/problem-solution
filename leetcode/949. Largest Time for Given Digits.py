from typing import List


class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:

        maxTime = -1

        def permutate(index):
            nonlocal maxTime
            if index == len(arr):
                hh = arr[0] * 10 + arr[1]
                mm = arr[2] * 10 + arr[3]
                if hh < 24 and mm < 60:
                    maxTime = max(maxTime, hh * 60 + mm)
            else:
                for next_index in range(index, len(arr)):
                    arr[index], arr[next_index] = arr[next_index], arr[index]
                    permutate(index + 1)
                    arr[index], arr[next_index] = arr[next_index], arr[index]

        permutate(0)
        return '' if maxTime < 0 else "{:02d}:{:02d}".format(maxTime // 60, maxTime % 60)

