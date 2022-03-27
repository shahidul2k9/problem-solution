
class _392_IsSubSequence {
    public boolean isSubsequence(String s, String t) {
        int k = 0;
        for (int i = 0; i < t.length() && k < s.length(); i++) {
            if (t.charAt(i) == s.charAt(k)) k++;
        }
        if (k == s.length()) return true;
        else return false;

    }
}