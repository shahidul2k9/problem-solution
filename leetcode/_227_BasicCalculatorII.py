class Solution:
    def calculate(self, s: str) -> int:
        def eval(a, b, op):
            match op:
                case '+':
                    return a + b
                case '-':
                    return a - b
                case '*':
                    return a * b
                case '/':
                    return int(a / b)

        operator_stack = []
        operand_stack = []
        n = ''
        pd = {'+': 1, '-': 1, '*': 2, '/': 2}
        for c in s:
            if c == ' ':
                if n != '':
                    operand_stack.append(int(n))
                    n = ''
            elif c in pd:
                if n != '':
                    operand_stack.append(int(n))
                n = '-' if c == '-' else ''
                if operator_stack and pd[operator_stack[-1]] >= pd[c]:
                    b, a = operand_stack.pop(), operand_stack.pop()
                    operand_stack.append(eval(a, b, operator_stack.pop()))
                operator_stack.append(c if c != '-' else '+')
            else:
                n += c

        if n != '':
            operand_stack.append(int(n))

        while operator_stack:
            b, a = operand_stack.pop(), operand_stack.pop()
            operand_stack.append(eval(a, b, operator_stack.pop()))
        return operand_stack.pop()

# print(Solution().calculate("1*2-3/4+5*6-7*8+9/10"))
# print(Solution().calculate("3+2*2"))
