import bisect


class HitCounter:

    def __init__(self):
        self.ht = []

    def hit(self, timestamp: int) -> None:
        self.ht.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        ht = self.ht
        left = bisect.bisect_left(ht, timestamp - 300 + 1)
        right = bisect.bisect_right(ht, timestamp)
        return right - left

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)