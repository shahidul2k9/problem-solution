class Solution(object):
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])
        stack = []
        for b in intervals:
            while stack and stack[-1][1] >= b[0]:
                a = stack.pop()
                b[0], b[1] = a[0], max(a[1], b[1])
            stack.append(b)
        return stack
