from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for ast in asteroids:
            while stack and ast != 0:
                t = stack[-1]
                if (ast > 0 and t > 0) or (ast < 0 and t < 0) or (t < 0 and ast > 0):
                    break
                elif abs(ast) == abs(t):
                    stack.pop()
                    ast = 0
                elif abs(ast) > abs(t):
                    stack.pop()
                else:
                    ast = 0
            if ast != 0:
                stack.append(ast)
        return stack
