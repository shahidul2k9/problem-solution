class MyCircularDeque:

    def __init__(self, k: int):
        self.q = [0] * k
        self.n = 0
        self.l = self.r = 0
        self.k = k

    def insertFront(self, value: int) -> bool:
        if self.n < self.k:
            if self.n == 0:
                return self.insertLast(value)
            else:
                self.l = self.l - 1
                self.q[self.l] = value
                self.n += 1
                return True
        else:
            return False

    def insertLast(self, value: int) -> bool:
        if self.n < self.k:
            self.q[self.r] = value
            self.r = (self.r + 1) % self.k
            self.n += 1
            return True
        else:
            return False

    def deleteFront(self) -> bool:
        if self.n > 0:
            self.l = (self.l + 1) % self.k
            self.n -= 1
            return True
        else:
            return False

    def deleteLast(self) -> bool:
        if self.n > 0:
            self.r -= 1
            self.n -= 1
            return True
        else:
            return False

    def getFront(self) -> int:
        if self.n > 0:
            return self.q[self.l]
        else:
            return -1

    def getRear(self) -> int:
        if self.n > 0:
            return self.q[self.r - 1]
        else:
            return -1

    def isEmpty(self) -> bool:
        return self.n == 0

    def isFull(self) -> bool:
        return self.n == self.k
