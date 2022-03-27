
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/2/2022
 **/
public class _6_ZigzagConversion {
    public String convert(String s, int numRows) {
        List<StringBuilder> stringList = new ArrayList<>();
        for (int r = 0; r < numRows; r++) {
            stringList.add(new StringBuilder());
        }
        int i = 0;
        int sl = s.length();
        while (i < sl) {
            for (int r = 0; r < numRows && i < sl; r++) {
                stringList.get(r).append(s.charAt(i++));
            }
            for (int br = numRows - 2; br > 0 && i < sl; br--) {
                stringList.get(br).append(s.charAt(i++));
            }
        }
        StringBuilder zigzagText = new StringBuilder();
        stringList.forEach(row -> zigzagText.append(row.toString()));
        return zigzagText.toString();

    }
}
