from bisect import bisect


class RangeModule:

    def __init__(self):
        self.intervals = []

    def addRange(self, left: int, right: int) -> None:
        lower_bound_index = bisect.bisect_left(self.intervals, left, key=lambda x: x[1])

        index = lower_bound_index
        while index < len(self.intervals):
            a, b = self.intervals[index]
            if a <= right and left <= b:
                left = min(a, left)
                right = max(b, right)
                index += 1
            else:
                break
        if index == lower_bound_index:
            self.intervals.insert(lower_bound_index, [left, right])
        else:
            self.intervals[lower_bound_index:index] = [[left, right]]
        # print(self.intervals)

    def queryRange(self, left: int, right: int) -> bool:
        lower_bound_index = bisect.bisect_left(self.intervals, left, key=lambda x: x[1])
        if lower_bound_index < len(self.intervals):
            start, end = self.intervals[lower_bound_index]
            return start <= left and end >= right
        return False

    def removeRange(self, left: int, right: int) -> None:
        lower_bound_index = bisect.bisect_left(self.intervals, left, key=lambda x: x[1])

        index = lower_bound_index
        edges = []
        while index < len(self.intervals):
            a, b = self.intervals[index]
            if a <= right and left <= b:
                common_left = max(a, left)
                common_right = min(b, right)
                if a < common_left:
                    edges.append([a, common_left])
                if common_right < b:
                    edges.append([common_right, b])
                index += 1
            else:
                break
        if lower_bound_index < index:
            self.intervals[lower_bound_index: index] = edges
        # print(self.intervals)

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)