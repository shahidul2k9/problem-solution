class Solution:
    def numPairsDivisibleBy60(self, time: list[int]) -> int:
        f = [0] * 60
        pt = 0
        for t in time:
            t = t % 60
            ct = (60 - t) % 60
            pt = pt + f[ct]
            f[t] = f[t] + 1
        return pt
