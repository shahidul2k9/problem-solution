import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for tc in range(1, T + 1, 1):
        N = int(sys.stdin.readline())
        a = list(map(int, sys.stdin.readline().split(' ')))
        left = 0
        right = len(a) - 1
        d = 0
        paid = 0
        while left <= right:
            if a[left] < a[right]:
                v = a[left]
                left += 1
            else:
                v = a[right]
                right -= 1
            if d <= v:
                paid += 1
                d = v
        print('Case #' + str(tc) + ': ' + str(paid))
