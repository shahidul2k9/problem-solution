class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        x = (hour % 12) + minutes / 60
        y = minutes / 5
        if x > y:
            x, y = y, x
        diff = min(y - x, x + 12 - y)

        return (diff / 12) * 360
