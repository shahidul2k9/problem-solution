class Solution:
    def uniqueLetterString(self, s: str) -> int:
        pm = collections.defaultdict(list)
        for i, c in enumerate(s):
            pm[c].append(i)
        n = len(s)

        count = 0
        for i, c in enumerate(s):
            positions = pm[c]
            lo = 0
            hi = len(positions)
            mid = 0
            while positions[mid] != i:
                mid = (lo + hi) // 2

                if positions[mid] < i:
                    lo = mid + 1
                elif positions[mid] > i:
                    hi = mid - 1

            left = positions[mid - 1] if mid > 0 else -1
            right = positions[mid + 1] if mid + 1 < len(positions) else n
            count += (i - left) * (right - i)
        return count

