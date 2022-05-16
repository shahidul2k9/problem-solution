from typing import List


class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        def reverse(x, y):
            while x < y:
                s[x], s[y] = s[y], s[x]
                x += 1
                y -= 1

        reverse(0, len(s) - 1)
        left = right = 0
        while right < len(s):
            while right < len(s) and s[right] != ' ':
                right += 1
            reverse(left, right - 1)
            right += 1
            left = right
