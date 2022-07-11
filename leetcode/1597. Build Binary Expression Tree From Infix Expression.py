class Node(object):
    def __init__(self, val=" ", left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def expTree(self, s: str) -> Node:
        precedence = {'(': -1, '+': 0, '-': 0, '*': 1, '/': 1}
        stack = []
        postfix = []
        for ch in s:
            if ch in ['+', '-', '*', '/', '(', ')']:
                if ch == '(' or not stack:
                    stack.append(ch)
                elif ch == ')':
                    while stack[-1] != '(':
                        right = postfix.pop()
                        left = postfix.pop()
                        postfix.append(Node(stack.pop(), left, right))
                    stack.pop()
                else:
                    while stack and precedence[stack[-1]] >= precedence[ch]:
                        right = postfix.pop()
                        left = postfix.pop()
                        postfix.append(Node(stack.pop(), left, right))
                    stack.append(ch)

            else:
                postfix.append(Node(ch))
        while stack:
            right = postfix.pop()
            left = postfix.pop()
            postfix.append(Node(stack.pop(), left, right))
        return postfix[-1]

