class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        ds = ''
        stack = []
        for c in s:
            if c =='[':
                stack.append(c)
            elif c == ',' and ds != '':
                stack.append(NestedInteger(int(ds)))
                ds = ''
            elif c == ']':
                if ds != '':
                    stack.append(NestedInteger(int(ds)))
                    ds = ''
                nsl = []
                while stack and stack[-1] != '[':
                    nsl.append(stack.pop())
                stack.pop()
                nsl.reverse()
                ns = NestedInteger()
                for x in nsl:
                    ns.add(x)
                stack.append(ns)
            elif c.isdigit() or c=='-':
                ds += c
        if stack:
            return stack[-1]
        elif ds != '':
            return NestedInteger(int(ds))