class Solution:
    def calculate(self, s: str) -> int:
        def eval(x, y, op) -> int:
            if op == '+':
                return x + y
            else:
                return x - y

        s = '(' + s.replace(' ', '') + ')'
        precedence = {'(': 0, '+': 1, '-': 2, ')': 3}
        i = 0
        n = len(s)
        operator_stack = []
        operand_stack = []

        while i < n:
            token = s[i]
            i += 1
            while token.isdigit() and i < n and s[i].isdigit():
                token = token + s[i]
                i += 1
            if token == '-' and s[i - 2] == '(':
                operand_stack.append(0)

            # print(operand_stack, operator_stack, token, s[i-1])

            if token in precedence:
                if token == ')':
                    while operator_stack[-1] != '(':
                        y = operand_stack.pop()
                        x = operand_stack.pop()
                        operand_stack.append(eval(x, y, operator_stack.pop()))
                    operator_stack.pop()
                elif token == '(':
                    operator_stack.append(token)
                else:
                    while operator_stack and precedence[operator_stack[-1]] >= precedence[token]:
                        y = operand_stack.pop()
                        x = operand_stack.pop()
                        operand_stack.append(eval(x, y, operator_stack.pop()))
                    operator_stack.append(token)
            else:
                operand_stack.append(int(token))

        return operand_stack[-1]

