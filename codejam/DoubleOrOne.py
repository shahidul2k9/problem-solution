import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for t in range(1, T + 1):
        text = sys.stdin.readline().strip()
        double_text = []
        larger_text = []
        for c in text:
            double_text.append(c)
            double_text.append(c)
            larger_text.append(c)
            larger_text.append(c)
        for i in range(len(larger_text) - 2, -1, -1):
            if ord(larger_text[i + 1]) > ord(larger_text[i]):
                larger_text[i] = max(larger_text[i], larger_text[i + 1])
        stack = []
        for i, c in enumerate(double_text):
            if i % 2 == 0:
                stack.append(c)
            else:
                for k in range(i + 1, len(double_text)):
                    if double_text[k] > double_text[i]:
                        stack.append(c)
                        break
                    elif double_text[k] < double_text[i]:
                        break
        ans = ''.join(stack)
        print("Case #" + str(t) + ": " + ans)
