from typing import List


class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        for i in range(len(arr) - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                max_val_index = i + 1
                for k in range(i + 1, len(arr)):
                    if arr[max_val_index] < arr[k] < arr[i]:
                        max_val_index = k
                arr[i], arr[max_val_index] = arr[max_val_index], arr[i]
                return arr
        return arr
