
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/10/2022
 **/
public class _274_HIndex {
    public int hIndex(int[] citations) {
        List<Integer> citationList = Arrays.stream(citations).boxed()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());
        int hIndex = 0;
        for (int i = 0; i < citationList.size(); i++) {
            if (citationList.get(i) >= i + 1) {
                hIndex = i + 1;
            }
        }
        return hIndex;

    }
}
