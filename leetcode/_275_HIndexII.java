
/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _275_HIndexII {
    public int hIndex(int[] citations) {
        int hIndex = 0;
        int lo = 0;
        int n = citations.length;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (citations[mid] >= n - mid) {
                hIndex = Math.max(hIndex, n - mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hIndex;

    }
}
