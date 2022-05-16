class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fb = [1, 1]
        while fb[-1] < 10 ** 9:
            fb.append(fb[-2] + fb[-1])

        count = 0
        idx = len(fb) - 1
        while k > 0:
            if fb[idx] > k:
                idx -= 1
            else:
                k -= fb[idx]
                count += 1
        return count
