
class _509_FibonacciNumber {
    static int[] fib = new int[31];

    static {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i < 31; i++) {
            fib[i] = fib[i - 2] + fib[i - 1];
        }
    }

    public int fib(int n) {
        return fib[n];
    }
}