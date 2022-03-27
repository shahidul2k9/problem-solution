class Solution(object):
    def robotSim(self, commands, obstacles):
        dxy = [(0, 1), (-1, 0), (0, -1), (1, 0)]
        obstacle_set = {(x, y) for x, y in obstacles}
        d = 0
        x, y = 0, 0
        max_d = 0
        for cmd in commands:
            if cmd == -2:
                d = (d + 1) % 4
            elif cmd == -1:
                d = (d + 3) % 4
            else:
                dx, dy = dxy[d]
                for i in range(cmd):
                    if (x + dx, y + dy) in obstacle_set:
                        break
                    else:
                        x, y = x + dx, y + dy
                        max_d = max(x ** 2 + y ** 2, max_d)
        return max_d
