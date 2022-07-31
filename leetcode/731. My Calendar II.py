from sortedcontainers import SortedDict


class MyCalendarTwo:

    def __init__(self):
        self.intervals = SortedDict(int)

    def book(self, start: int, end: int) -> bool:
        iv = self.intervals
        iv.setdefault(start, 0)
        iv.setdefault(end, 0)
        iv[start] += 1
        iv[end] -= 1
        max_depth = depth = 0
        for key in iv.keys():
            depth += iv[key]
            max_depth = max(max_depth, depth)
        if max_depth >= 3:
            iv[start] -= 1
            iv[end] += 1
            return False
        else:
            return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)