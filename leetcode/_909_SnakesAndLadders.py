import collections
from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        thread = [0]
        R = len(board)
        for r in range(len(board)):
            if r % 2 == 0:
                thread.extend(board[R - r - 1])
            else:
                thread.extend(board[R - r - 1][::-1])
        n = len(thread) - 1

        q = collections.deque()
        q.append([1, 0])
        seen = {1}
        while q:
            cur_n, d = q.popleft()
            if cur_n == n:
                return d
            for dice_face in range(1, 7, 1):
                next_n = cur_n + dice_face
                if next_n <= n:
                    if thread[next_n] != -1:
                        next_n = thread[next_n]
                    if next_n not in seen:
                        q.append([next_n, d + 1])
                        seen.add(next_n)

        return -1


