
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _131_PalindromePartitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> partitionList = new ArrayList<>();
        bk(s, 0, new ArrayList<>(), partitionList);
        return partitionList;
    }

    private void bk(String s, int pos, List<String> prefixPartition, List<List<String>> partitionList) {
        if (pos == s.length()) {
            partitionList.add(new ArrayList<>(prefixPartition));
        } else {
            for (int i = pos; i < s.length(); i++) {
                if (isPalindrome(s, pos, i)) {
                    String ps = s.substring(pos, i + 1);
                    prefixPartition.add(ps);
                    bk(s, i + 1, prefixPartition, partitionList);
                    prefixPartition.remove(prefixPartition.size()-1);
                }
            }
        }

    }

    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
