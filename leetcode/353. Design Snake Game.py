import collections
from typing import List


class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.width = width
        self.height = height
        self.food_seq = [(r, c) for r, c in food][::-1]
        self.tail_seq = collections.deque([(0, 0)])
        self.tail_set = set([(0, 0)])
        self.r = 0
        self.c = 0
        self.is_over = False
        self.score = 0
        # print(vars(self))

    def move(self, direction: str) -> int:
        if self.is_over:
            return -1
        else:
            mvp = {'R': (0, 1), 'D': (1, 0), 'L': (0, -1), 'U': (-1, 0)}
            dr, dc = mvp[direction]
            nr = self.r + dr
            nc = self.c + dc
            next_pos = (nr, nc)
            if 0 <= nr < self.height and 0 <= nc < self.width and (
                    next_pos not in self.tail_set or next_pos == self.tail_seq[0]):

                if len(self.food_seq) > 0 and next_pos == self.food_seq[-1]:
                    self.score += 1
                    self.food_seq.pop()
                else:
                    self.tail_set.remove(self.tail_seq.popleft())

                self.tail_seq.append(next_pos)
                self.tail_set.add(next_pos)
                self.r = nr
                self.c = nc
                return self.score
            else:
                self.is_over = True
                return -1

# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)