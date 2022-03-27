
/**
 * @author Shahidul Islam
 * @date 2/16/2022
 **/
public class _443_StringCompression {
    public int compress(char[] chars) {
        int l = 0;
        int left = 0;
        for (int k = 1; k < chars.length; k++) {
            if (chars[k - 1] != chars[k]) {
                int f = k - left;
                l += compressChar(f, chars, l, chars[left]);
                left = k;
            }
        }
        l += compressChar(chars.length - left, chars, l, chars[left]);
        return l;

    }

    private int compressChar(int f, char[] seq, int l, char ch) {
        String fText = String.valueOf(f);
        seq[l] = ch;
        if (f > 1) {
            int fid = 0;
            while (fid < fText.length()) {
                seq[l+fid+1] = fText.charAt(fid);
                fid++;
            }
        }

        if (f == 1)
            return 1;
        else {
            return fText.length() + 1;
        }
    }
}
