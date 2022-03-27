class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        mi = []
        i = 0
        for i in range(len(intervals)):
            print(i)
            if intervals[i][0] < newInterval[0]:
                mi.append(intervals[i])
            else:
                break
        print(i)

        while newInterval:
            if mi and self.doesIntersect(mi[-1], newInterval):
                newInterval = [min(mi[-1][0], newInterval[0]), max(mi[-1][1], newInterval[1])]
                mi.pop()
            mi.append(newInterval)

            if i < len(intervals):
                newInterval = intervals[i]
                i += 1
            else:
                newInterval = None
        return mi

    def doesIntersect(self, in1, in2):
        return in1[0] <= in2[1] and in1[1] >= in2[0]

print(Solution().insert([[1,5]], [6,8]))
