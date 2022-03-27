
import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Stream;

/**
 * @author Shahidul Islam
 * @date 1/31/2022
 **/
public class _179_LargestNumber {
    public String largestNumber(int[] nums) {

        int[] sortedArray = Arrays.stream(nums)
                .boxed()
                .sorted((o1, o2) -> {
                    String textX = o1.toString();
                    String textY = o2.toString();
                    return -1 * (textX + textY).compareTo(textY + textX);
                })
                .mapToInt(i -> i)
                .toArray();

        StringBuilder bigNumberBuilder = new StringBuilder();

        for (int val : sortedArray) {
            bigNumberBuilder.append(val);

        }

        String numberText = bigNumberBuilder.toString();
        int zeroCount = 0;
        for (int i = 0; i < numberText.length(); i++) {
            if (numberText.charAt(i) == '0') zeroCount++;
        }
        if (zeroCount == numberText.length()) return "0";
        else
            return numberText;
    }
}
