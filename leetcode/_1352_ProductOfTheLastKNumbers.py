import bisect


class ProductOfNumbers:

    def __init__(self):
        self.z = []  # 0 based index
        self.p = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.z.append(len(self.p) - 1)
            self.p.append(self.p[-1])
        else:
            self.p.append(self.p[-1] * num)

    def getProduct(self, k: int) -> int:
        ni = bisect.bisect_left(self.z, len(self.p) - k, 0)
        if ni < len(self.z):
            return 0
        else:
            return self.p[-1] // self.p[len(self.p) - k - 1]
