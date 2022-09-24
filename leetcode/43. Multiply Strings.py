class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = len(num1)
        n2 = len(num2)
        ans = [0] * (n1 + n2 + 1)
        for j in range(n2 - 1, -1, -1):
            d2 = ord(num2[j]) - ord('0')
            carry = 0
            index = n2 - 1 - j
            for i in range(n1 - 1, -1, -1):
                d1 = ord(num1[i]) - ord('0')
                d = d1 * d2 + carry + ans[index]
                ans[index] = d % 10
                carry = d // 10
                index += 1
            ans[index] += carry

        while len(ans) > 0 and ans[-1] == 0:
            ans.pop()
        if len(ans) == 0:
            return '0'
        else:
            m = []
            for d in ans:
                m.append(chr(48 + d))
            return ''.join(m[::-1])