class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        l = 1
        while len(self.stack) >= l and self.stack[-l][0] <= price:
            l = l + self.stack[-l][1]
        self.stack.append((price, l))
        return l
