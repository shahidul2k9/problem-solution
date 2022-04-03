import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for tc in range(1, T + 1, 1):
        m = [float('inf')] * 4
        for i in range(3):
            p = list(map(int, sys.stdin.readline().split(' ')))
            for c in range(4):
                m[c] = min(m[c], p[c])
        s = sum(m)
        print('Case #' + str(tc) + ':', end='')
        if s < 10 ** 6:
            print(' IMPOSSIBLE')
        else:
            r = 10 ** 6
            for c in range(4):
                ink = min(r, m[c])
                r -= ink
                print(' ' + str(ink), end=' ')
            print('')
