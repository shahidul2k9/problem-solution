
class _338_CountBits {
    static int[] bits = new int[100002];

    static {
        for (int i = 0; i < 100002; i++) {
            int cnt = 0;
            for (int k = 0; k < 30; k++) {
                if (((1 << k) & i) != 0) {
                    cnt++;
                }
            }
            bits[i] = cnt;
        }
    }

    public int[] countBits(int n) {
        int[] x = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            x[i] = bits[i];
        }
        return x;
    }
}