
/**
 * @author Shahidul Islam
 * @date 2/16/2022
 **/
public class _167_TwoSumIIInputArrayIsSorted {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        for (int i = 0; i < n - 1; i++) {
            int sendValIndex = binarySearch(i + 1, n - 1, numbers, target - numbers[i]);
            if (sendValIndex != -1) {
                return new int[]{i + 1, sendValIndex + 1};
            }
        }
        return new int[]{0, 0};

    }

    private int binarySearch(int low, int hi, int[] a, int target) {
        while (low <= hi) {
            int mid = (hi + low) / 2;
            if (a[mid] == target)
                return mid;
            else if (a[mid] < target) {
                low = mid + 1;
            } else
                hi = mid - 1;
        }
        return -1;
    }
}
