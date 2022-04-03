import sys

if __name__ == '__main__':
    tc = int(sys.stdin.readline())
    char_map = [['+', '-'], ['|', '.']]
    ct = 1
    while ct <= tc:
        print('Case #' + str(ct) + ':')
        line = sys.stdin.readline()

        R, C = line.split(' ')
        R, C = 2 * int(R) + 1, 2 * int(C) + 1
        for r in range(R):
            for c in range(C):
                if 0 <= r <= 1 and 0 <= c <= 1:
                    print('.', end='')
                else:
                    print(char_map[r % 2][c % 2], end='')
                if c == C - 1:
                    print('')
        ct += 1
