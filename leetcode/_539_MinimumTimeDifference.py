from typing import List


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minute_seq = [int(hhmm[:2]) * 60 + int(hhmm[3:]) for
                      hhmm in timePoints]
        minute_seq.sort()
        minute_seq.append(minute_seq[0] + 1440)
        min_dif = float('inf')
        for i in range(len(minute_seq) - 1):
            min_dif = min(min_dif, minute_seq[i + 1] - minute_seq[i], 1440 + minute_seq[i] - minute_seq[i + 1])
        return min_dif
