import math


class Solution:
    def calculate(self, s: str) -> int:
        def eval(x, y, operator) -> int:
            match operator:
                case '+':
                    return x + y
                case '-':
                    return x - y
                case '*':
                    return x * y
                case '/':
                    div = x / y
                    if div < 0:
                        return math.ceil(div)
                    else:
                        return math.floor(div)

        def eval_top_term():
            y = stack.pop()
            x = stack.pop()
            stack.append(eval(x, y, op_stack.pop()))

        stack = []
        op_stack = []
        precedence = {'(': 0, '+': 1, '-': 2, '*': 3, '/': 3, ')': 4}
        s = '(' + s + ')'
        i = 0
        n = len(s)
        while i < n:
            token = s[i]
            i += 1
            while token.isdigit() and i < n and s[i].isdigit():
                token += s[i]
                i += 1
            if token in precedence:
                if token == '(':
                    op_stack.append(token)
                elif token == ')':
                    while op_stack[-1] != '(':
                        eval_top_term()
                    op_stack.pop()
                else:
                    while op_stack and precedence[op_stack[-1]] >= precedence[token]:
                        eval_top_term()
                    op_stack.append(token)
            else:
                stack.append(int(token))
        return stack[-1]

