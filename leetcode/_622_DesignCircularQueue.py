class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [0] * k
        self.n = 0
        self.l = self.r = 0
        self.k = k

    def enQueue(self, value: int) -> bool:
        if self.n < self.k:
            self.q[self.r] = value
            self.r = (self.r + 1) % self.k
            self.n += 1
            return True
        else:
            return False

    def deQueue(self) -> bool:
        if self.n > 0:
            self.l = (self.l + 1) % self.k
            self.n -= 1
            return True
        else:
            return False

    def Front(self) -> int:
        if self.n > 0:
            return self.q[self.l]
        else:
            return -1

    def Rear(self) -> int:
        if self.n > 0:
            return self.q[self.r - 1]
        else:
            return -1

    def isEmpty(self) -> bool:
        return self.n == 0

    def isFull(self) -> bool:
        return self.n == self.k
