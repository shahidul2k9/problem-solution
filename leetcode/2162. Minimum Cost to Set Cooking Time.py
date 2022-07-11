class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        mm = targetSeconds // 60
        ss = targetSeconds % 60

        def calculateCost() -> int:
            seq = '{:02d}{:02d}'.format(mm, ss)
            seq = seq.lstrip('0')
            totalCost = 0
            currentAt = startAt
            for d in seq:
                targetDigit = ord(d) - ord('0')
                if targetDigit != currentAt:
                    currentAt = targetDigit
                    totalCost += moveCost
                totalCost += pushCost
            return totalCost

        if mm <= 99:
            optimalCost = calculateCost()
        else:
            optimalCost = float('inf')

        if mm > 0 and ss <= 39:
            mm -= 1
            ss += 60
            optimalCost = min(calculateCost(), optimalCost)
        return optimalCost





