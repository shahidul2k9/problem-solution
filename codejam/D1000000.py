import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for tc in range(1, T + 1, 1):
        N = int(sys.stdin.readline())
        a = list(map(int, sys.stdin.readline().split(' ')))
        a.sort()
        c = 0
        for v in a:
            if c + 1 <= v:
                c += 1
        print('Case #' + str(tc) + ': ' + str(c))
