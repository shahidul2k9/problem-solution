import abc
from abc import ABC, abstractmethod

"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""


class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass


class ExpNode(Node):
    def __init__(self, op: str, val: int, left: Node, right: Node):
        self.op = op
        self.val = val
        self.left = left
        self.right = right

    def evaluate(self) -> int:
        left = self.left
        right = self.right
        match self.op:
            case '+':
                return left.evaluate() + right.evaluate()
            case '-':
                return left.evaluate() - right.evaluate()
            case '*':
                return left.evaluate() * right.evaluate()
            case '/':
                return left.evaluate() // right.evaluate()
            case None:
                return self.val


"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""


class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stack = []
        for ps in postfix:
            if ps not in ['+', '-', '*', '/']:
                stack.append(ExpNode(None, int(ps), None, None))
            else:
                right = stack.pop()
                left = stack.pop()
                stack.append(ExpNode(ps, 0, left, right))
        return stack[-1]


"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
