class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [None] * 5001
        self.total = 0
        self.n = 0
        self.visit(homepage)

    def visit(self, url: str) -> None:
        self.history[self.n] = url
        self.n = self.total = self.n + 1

    def back(self, steps: int) -> str:
        self.n = max(1, self.n - steps)
        return self.history[self.n - 1]

    def forward(self, steps: int) -> str:
        self.n = min(self.total, self.n + steps)
        return self.history[self.n - 1]
