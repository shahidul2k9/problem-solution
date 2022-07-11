from heapq import heappush, heappop


class StockPrice:

    def __init__(self):
        self.clock = 0
        self.min_pq = []
        self.max_pq = []
        self.latest = [-1, -1]
        self.timestamp_to_clock = {}

    def update(self, timestamp: int, price: int) -> None:
        self.clock += 1
        heappush(self.min_pq, [price, timestamp, self.clock])
        heappush(self.max_pq, [-price, timestamp, self.clock])
        latest_price, latest_timestamp = self.latest
        if latest_timestamp <= timestamp:
            self.latest = [price, timestamp]
        self.timestamp_to_clock[timestamp] = self.clock

    def current(self) -> int:
        return self.latest[0]

    def maximum(self) -> int:
        while True:
            price, timestamp, clock = self.max_pq[0]
            if self.timestamp_to_clock[timestamp] != clock:
                heappop(self.max_pq)
            else:
                return -price

    def minimum(self) -> int:
        while True:
            price, timestamp, clock = self.min_pq[0]
            if self.timestamp_to_clock[timestamp] != clock:
                heappop(self.min_pq)
            else:
                return price

# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()