class Solution:
    def countCollisions(self, directions: str) -> int:
        collisions = 0
        stack = []
        for d in directions:
            if not stack:
                stack.append(d)
            else:
                match d:
                    case 'S':
                        c = 0
                        while stack and stack[-1] == 'R':
                            c += 1
                            stack.pop()
                        if c > 0:
                            collisions += c
                        stack.append('S')
                    case 'L':
                        c = 0
                        while stack and stack[-1] == 'R':
                            c += 1
                            stack.pop()
                        if c > 0:
                            collisions = collisions + 2 + (c-1)
                            stack.append('S')
                        elif stack[-1] == 'S':
                            collisions += 1
                            stack.append('S')
                        else:
                            stack.append('L')
                    case 'R':
                        stack.append('R')
        return collisions
