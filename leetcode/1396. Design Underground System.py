class UndergroundSystem:

    def __init__(self):
        self.check_in = {}  # id -> (stationName, t)
        self.history = {}  # (startStation, endStation) -> (n, total_time)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in[id] = [stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, startTime = self.check_in[id]
        route_key = (startStation, stationName)
        if route_key not in self.history:
            self.history[route_key] = [0, 0]
        statistics = self.history[route_key]
        statistics[0] += 1
        statistics[1] += (t - startTime)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        travel_count, total_distance = self.history[(startStation, endStation)]
        return total_distance / travel_count

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)