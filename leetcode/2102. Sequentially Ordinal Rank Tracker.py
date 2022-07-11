from heapq import heappush, heappop


class Item:
    def __init__(self, score: int, name: str):
        self.score = score
        self.name = name

    def __lt__(self, other) -> bool:
        if self.score != other.score:
            return self.score < other.score
        else:
            return self.name > other.name

    def __repr__(self):
        return str(self.score) + " " + self.name


class ReverseItem:
    def __init__(self, score: int, name: str):
        self.score = score
        self.name = name

    def __lt__(self, other) -> bool:
        if self.score != other.score:
            return self.score > other.score
        else:
            return self.name < other.name

    def __repr__(self):
        return str(self.score) + " " + self.name


class SORTracker:

    def __init__(self):
        self.min_best_queue = []
        self.max_queue = []
        self.i = 0

    def transfer(self, q1, q2, from_min):

        item = heappop(q1)
        if from_min:
            moved_item = ReverseItem(item.score, item.name)
        else:
            moved_item = Item(item.score, item.name)
        heappush(q2, moved_item)

    def add(self, name: str, score: int) -> None:
        min_q = self.min_best_queue
        max_q = self.max_queue
        heappush(min_q, Item(score, name))

        self.transfer(min_q, max_q, True)

        self.transfer(max_q, min_q, False)

        if self.i + 1 < len(min_q):
            self.transfer(min_q, max_q, True)

    def get(self) -> str:
        min_q = self.min_best_queue
        max_q = self.max_queue
        # print(self.i, len(min_q))
        # print(min_q,'---------', max_q)
        if self.i >= len(min_q):
            self.transfer(max_q, min_q, False)
        name = min_q[0].name
        self.i += 1
        return name

# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()