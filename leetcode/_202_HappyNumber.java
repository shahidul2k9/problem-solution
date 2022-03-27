
import java.util.HashMap;
import java.util.Map;

class _202_HappyNumber {
    public boolean isHappy(int n) {
        Map<Integer, Boolean> track = new HashMap<>();
        while (n != 1 ) {
            int s = 0;
            while (n != 0) {
                s += Math.pow(n % 10, 2);
                n = n / 10;
            }
            n = s;
            if(track.containsKey(n)){
                break;
            }
            track.put(n, true);
        }

        if (n == 1) return true;
        else return false;
    }
}