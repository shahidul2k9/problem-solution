
/**
 * @author Shahidul Islam
 * @date 2/16/2022
 **/
public class _38_CountAndSay {
    private static final String[] cs = new String[30];

    static {
        cs[0] = "1";
        for (int i = 1; i < 30; i++) {
            String prevText = cs[i - 1];
            int cn = 1;
            StringBuilder csBuilder = new StringBuilder();
            int prevLength = prevText.length();
            for (int k = 1; k < prevLength; k++) {
                if (prevText.charAt(k - 1) != prevText.charAt(k)) {
                    csBuilder.append(cn).append(prevText.charAt(k - 1));
                    cn = 1;
                } else {
                    cn++;
                }
            }
            csBuilder.append(cn).append(prevText.charAt(prevLength - 1));
            cs[i] = csBuilder.toString();
        }
    }

    public String countAndSay(int n) {
        return cs[n - 1];

    }
}
