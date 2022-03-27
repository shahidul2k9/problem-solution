
class _70_ClimbingStairs {
    static int [] ways = new int[46];
    static {
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i < 46; i++){
            ways[i] = ways[i-2] + ways[i-1];
        }
    }
    public int climbStairs(int n) {
        return ways[n];
    }
}