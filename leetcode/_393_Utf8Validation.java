
/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _393_Utf8Validation {
    public boolean validUtf8(int[] data) {
        int n = data.length;
        for (int i = 0; i < n; i++) {
            //System.out.println(Integer.toBinaryString(data[i]));
            int bc = countBytes(data[i]);
            if (bc > 4)
                return false;
            if (bc > 1) {
                if (bc + i > n)
                    return false;
                while (bc > 1) {
                    if (data[i + 1] >> 6 != 2)
                        return false;
                    bc--;
                    i = i + 1;
                }
            }
        }
        return true;
    }

    private int countBytes(int val) {
        int sh = 1 << 7;
        int bc = 0;
        while ((sh & val) != 0) {
            bc++;
            sh = sh >> 1;
        }
        if (bc == 1)
            return 8;
        return bc > 0 ? bc : 1;
    }
}
