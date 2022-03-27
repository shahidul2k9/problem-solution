class Solution(object):
    def validateStackSequences(self, pushed, popped):
        stack = []
        popped.reverse()
        for v in pushed:
            stack.append(v)
            while stack and popped and stack[-1] == popped[-1]:
                popped.pop()
                stack.pop()
        return len(stack) == 0