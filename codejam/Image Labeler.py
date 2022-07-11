import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for tc in range(1, T + 1, 1):
        nm = sys.stdin.readline().split()
        n = int(nm[0])
        m = int(nm[-1])
        areas = sys.stdin.readline().split()
        for i, a in enumerate(areas):
            areas[i] = int(a)
        areas.sort()
        s = 0
        i = 0
        while i < m - 1:
            s += areas[n - 1 - i]
            i += 1
        rn = n - (m - 1)
        if rn % 2 == 1:
            s += areas[rn //2]
        else:
            s = s + (areas[rn // 2 - 1] + areas[rn//2])/2.0
        print('Case #' + str(tc) + ': ' + str(s) )
