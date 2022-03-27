
/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _521_LongesUncommonSubsequenceI {
    public int findLUSlength(String a, String b) {

        if (a.equals(b)) {
            return -1;
        } else return Math.max(a.length(), b.length());
    }
}
