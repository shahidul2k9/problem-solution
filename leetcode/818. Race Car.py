import collections


class Solution:
    def racecar(self, target: int) -> int:
        q = collections.deque([[0, 1, 0]])#pos,speed,steps
        visited = {(0, 1)} #pos,speed
        while q:
            pos, speed, steps = q.popleft()
            if pos == target:
                return steps
            next_moves = [[ pos + speed, speed * 2, steps + 1]]
            # +speed ==> avoid early backward walk
            if pos + speed > target and speed > 0:
                next_moves.append([pos, -1, steps + 1])
            if pos + speed < target and speed <= 0:
                next_moves.append([pos, 1, steps + 1])
            for next_pos, next_speed, next_steps in next_moves:
                if (next_pos, next_speed) not in visited:
                    visited.add((next_pos, next_speed))
                    q.append([next_pos, next_speed, next_steps])
                    # if next_pos == target:
                    #     return next_steps