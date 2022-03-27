
/**
 * @author Shahidul Islam
 * @date 2/18/2022
 **/
public class _2161_PartitionArrayAccordingToGivenPivot {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] partition = new int[n];
        int pi = 0;
        int ni = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                partition[pi++] = nums[i];
            if (nums[n - 1 - i] > pivot)
                partition[ni--] = nums[n - 1 - i];
        }
        for (int i = pi; i <= ni; i++) {
            partition[i] = pivot;
        }
        return partition;
    }
}
