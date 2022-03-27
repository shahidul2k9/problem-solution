
class _14_LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        int prefixLength = 0;
        char ch;

        String text = strs[0];
        for (int i = 0; i < text.length(); i++) {
            ch = text.charAt(i);
            int j = 1;
            for (j = 1; j < strs.length && prefixLength < strs[j].length() && strs[j].charAt(prefixLength) == ch; j++) {
            }
            if (j != strs.length) break;
            else prefixLength++;
        }
        return text.substring(0, prefixLength);
    }
}