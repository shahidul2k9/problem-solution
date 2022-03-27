class Solution:
    def decodeString(self, s: str) -> str:
        count_tack = []
        text_stack = []
        k = ''
        es = ''
        for t in s:
            if t == '[':
                count_tack.append(k)
                text_stack.append(es)
                k = ''
                es = ''
            elif t == ']':
                es = text_stack.pop() + ''.join([es for _ in range(int(count_tack.pop()))])
            elif t.isdigit():
                k += t
            else:
                es += t
        if es != '':
            text_stack.append(es)
        return ''.join(text_stack)


#print(Solution().decodeString("3[a2[c]]"))
