from typing import List


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        reverse_count = 0

        def merge_and_count(nums1: List[int], nums2: List[int]) -> List[int]:
            nonlocal reverse_count
            n1 = len(nums1)
            n2 = len(nums2)
            i = j = 0
            nums3 = []

            while i < n1 and j < n2:
                if nums1[i] > 2 * nums2[j]:
                    reverse_count += n1 - i
                    j += 1
                else:
                    i += 1
            i = j = 0
            while i < n1 and j < n2:
                if nums1[i] < nums2[j]:
                    nums3.append(nums1[i])
                    i += 1
                else:
                    nums3.append(nums2[j])
                    j += 1
            while i < n1:
                nums3.append(nums1[i])
                i += 1
            while j < n2:
                nums3.append(nums2[j])
                j += 1
            return nums3

        def sort(left: int, right: int) -> List[int]:
            if left < right:
                mid = (left + right) // 2
                left_nums = sort(left, mid)
                right_nums = sort(mid + 1, right)
                return merge_and_count(left_nums, right_nums)
            else:
                return [nums[left]]

        sort(0, len(nums) - 1)
        return reverse_count

