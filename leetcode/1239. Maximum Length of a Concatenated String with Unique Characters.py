from typing import List
import collections
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        n = len(arr)

        def augment_frequency(frequency: dict, block_size: int, arr_index: int):
            for ch in arr[arr_index]:
                frequency[ch] += block_size

        def bracktrack(index: int, frequency: dict, count: int) -> int:
            ans = count
            if index < n:
                ans = bracktrack(index + 1, frequency, count)
                augment_frequency(frequency, 1, index)
                for ch in arr[index]:
                    if frequency[ch] > 1:
                        augment_frequency(frequency, -1, index)
                        break
                else:  # no overlap
                    ans = max(ans, bracktrack(index + 1, frequency, count + len(arr[index])))
                    augment_frequency(frequency, -1, index)
            return ans

        return bracktrack(0, collections.defaultdict(int), 0)
