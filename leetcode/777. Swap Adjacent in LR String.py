class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        i = k = 0
        while i < n or k < n:
            while i < n and start[i] == 'X':
                i += 1
            while k < n and end[k] == 'X':
                k += 1
            if i == n and k == n:
                return True
            elif i == n or k == n or start[i] != end[k]:
                return False

            if (start[i] == 'L' and i < k) or (start[i] == 'R' and i > k):
                return False
            i += 1
            k += 1
        return True

