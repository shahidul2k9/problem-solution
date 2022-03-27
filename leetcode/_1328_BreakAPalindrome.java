
/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _1328_BreakAPalindrome {
    public String breakPalindrome(String palindrome) {

        String nextP = "";
        int n = palindrome.length();
        if (n <= 1) {
            return nextP;
        } else {
            char[] chars = palindrome.toCharArray();
            int skipMid = n % 2 != 0 ? n / 2 : n;
            for (int i = 0; i < chars.length; i++) {
                char ch = chars[i];
                if (i != skipMid && ch != 'a') {
                    chars[i] = 'a';
                    nextP = new String(chars);
                    break;
                }
            }
            if (nextP.isEmpty()) {
                chars[n - 1]++;
                nextP = new String(chars);
            }
        }

        return nextP;
    }
}
