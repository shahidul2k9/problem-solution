import math
from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            match token:
                case '+':
                    stack.append(stack.pop() + stack.pop())
                case '*':
                    stack.append(stack.pop() * stack.pop())
                case '/':
                    b = stack.pop()
                    q = stack.pop() / b
                    stack.append(math.floor(q) if q >= 0 else math.ceil(q))
                case '-':
                    stack.append(-(stack.pop() - stack.pop()))
                case x:
                    stack.append(int(x))
        return stack[-1]
